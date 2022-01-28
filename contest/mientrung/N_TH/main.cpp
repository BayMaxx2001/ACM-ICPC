#include <bits/stdc++.h>
#define maxn 200005
using namespace std;

int dem[maxn][30];
int cntSL[maxn];
int n, m, a[maxn];
int last[maxn];
int r[maxn][30];
string s, t;
void read()
{
    cin >> s >> t;
    n = s.size();
    m = t.size();
    s = ' ' + s;
    t = ' ' + t;
    for(int i=0;i<=25;i++)
    {
        last[i] = n + 1;
    }
    for(int i=1;i<=m;i++)
    {
        cntSL[t[i]-'a']++;
    }

    for(int i=1;i<=n;i++)
    {

        for(int j=0;j<=25;j++)
        {
            dem[i][j] = dem[i-1][j];
            dem[i][s[i]-'a'] ++;
        }
    }

    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<=25;j++)
        {
            r[i][j]= last[j];
        }
        last[s[i]-'a'] = i;
    }
    for(int i=0;i<=25;i++) r[0][i] = last[i];
}
bool check( int vt)
{
    for(int i=0;i<=25;i++)
    {
        if(dem[n][i] - dem[vt-1][i] < cntSL[i])
            return false;
    }
    return true;
}
void solve()
{
    for(int i=0;i<=25;i++)
    {
        if (cntSL[i] > dem[n][i])
        {
            cout << -1;
            return ;
        }
    }
    int index = 0;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<=25;j++)
        {
            if( cntSL[j] <= 0 ) continue;
            int vt = r[index][j];
            if ( check(vt) == true )
            {
                cout << char(j+'a');
                cntSL[j]--;
                index = r[index][j];
                break;
            }
        }
    }
}
int main()
{
    read();
    solve();
    return 0;
}
