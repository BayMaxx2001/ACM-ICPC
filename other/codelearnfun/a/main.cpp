#include <bits/stdc++.h>
#define maxn 50007
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define foru(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= b; --i)
#define endl "\n";
using namespace std;
long long m, s[maxn];
struct banghi
{
    long long x, y;
} a[maxn];

bool cmpX(banghi a, banghi b)
{
    return a.x < b.x;
}
bool cmpY(banghi a, banghi b)
{
    return a.y < b.y;
}

long long sqr(long long a)
{
    return a * a;
}

long long distance(banghi a, banghi b)
{
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}
long long ans = 1e18;
vector<banghi> st;
void cal(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    cal(l, mid);
    cal(mid + 1, r);
    st.clear();
    foru(i, l, r)
    {
        if (sqr(a[i].x - a[mid].x) <= ans)
        {
            st.emplace_back(a[i]);
        }
    }
    sort(all(st), cmpY);
    foru(i, 0, st.size() - 1)
    {
        foru(j, i + 1, st.size() - 1)
        {
            if (abs(st[i].x - st[j].x) > 1)
                ans = min(ans, distance(st[i], st[j]));
        }
    }
}

long long poison(int n, std::vector<int> p)
{
    foru(i, 1, n)
    {
        s[i] = s[i - 1] + p[i - 1];
        a[i] = {i - 1, s[i - 1]};
    }
    a[++n] = {n - 1, s[n - 1]};
    sort(a + 1, a + 1 + n, cmpX);
    ans = distance(a[1], a[3]);
    cal(1, n);
    return ans;
}
