#include <bits/stdc++.h>
#define maxn 100004
#define ll long long
using namespace std;

const int N = 100005;
string s;
int n;
vector <int> odd[2], even[2];
ll ans = 0;
void solve()
{
    int typeodd = 0, typeeven = 0;
    for (char c : s)
    {
        if (c == '0')
        {
            for (int &i : even[typeeven])
            {
                i /= 2;
                ans -= i;
                if (i & 1)
                {
                    odd[typeodd].push_back(i);
                }
                else
                {
                    even[1 - typeeven].push_back(i);
                }
            }
            even[typeeven].clear();
            typeeven = 1 - typeeven;
        }
        else
        {
            for (int& i : odd[typeodd])
            {
                ans--;
                i--;
                if (i == 0) continue;
                even[typeeven].push_back(i);
            }
            odd[typeodd].clear();
            typeodd = 1 - typeodd;
        }
        cout << ans << endl;
    }
}
void read()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        ans += x;
        if (x & 1)
        {
            odd[0].push_back(x);
        }
        else
        {
            even[0].push_back(x);
        }
    }
    cin >> s;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    read();
    solve();
    return 0;
}
