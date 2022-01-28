#include <bits/stdc++.h>
#define maxn 100007
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define pb push_back
#define int long long
#define foru(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= b; --i)
#define bit(i) (i & (-i))
#define ii pair<int, int>
#define eb emplace_back
#define endl "\n";
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
const int mod = 1e9 + 7;
string yno[] = {"NO", "YES"};

int n, m, a[maxn];
string s, t;
int cntB[26];
void readAndPrepare()
{
    cin >> s >> t;
    n = s.size();
    m = t.size();
    s = ' ' + s;
    t = ' ' + t;
}
int cnt[maxn][26];
int last[26];
int r[maxn][26];
void solve()
{
    foru(i, 1, m)
    {
        int c = t[i] - 'a';
        cntB[c]++;
    }
    foru(i, 1, n)
    {
        foru(j, 0, 25) cnt[i][j] = cnt[i - 1][j];
        int c = s[i] - 'a';
        cnt[i][c]++;
    }
    foru(i, 0, 25) last[i] = n + 1;
    ford(i, n, 1)
    {
        foru(j, 0, 25)
        {
            r[i][j] = last[j];
        }
        if (i != 0)
        {
            int c = s[i] - 'a';
            last[c] = i;
        }
    }

    foru(j, 0, 25) r[0][j] = last[j];
    int cur = 0;
    foru(i, 0, 25)
    {
        if (cntB[i] > cnt[n][i])
        {
            cout << -1;
            return;
        }
    }

    foru(i, 1, m)
    {
        // cout << cur;
        foru(j, 0, 25)
        {
            bool ok = true;
            if (cntB[j] > 0)
            {
                int k = r[cur][j];
                if (i == 2 && j == 0)
                {
                    // cout << cur << " " << k << endl;
                }
                foru(l, 0, 25)
                {
                    if (cnt[n][l] - cnt[k - 1][l] < cntB[l])
                        ok = false;
                }
                if (ok)
                {
                    cout << char(j + 'a');
                    cntB[j]--;
                    cur = r[cur][j];
                    break;
                }
            }
        }
    }
}
#undef int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int test = 1;
    int tc = 0;
    // cin >> test;
    while (test--)
    {
        // cout << "TestCase "<<++tc<<" :";
        readAndPrepare();
        solve();
    }
    return 0;
}
