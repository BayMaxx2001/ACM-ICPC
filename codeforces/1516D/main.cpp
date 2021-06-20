#include <bits/stdc++.h>
#define PB push_back
#define maxn 100005
using namespace std;
int n , q;
int a[maxn];
vector < int > pri[maxn+10];
void read()
{
    cin >> n >> q;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
}
int F[maxn][30];
int nex[maxn];
void solve()
{
    for (int i=2;i<=maxn;i++)
    {
        if (pri[i].empty())
        {
            nex[i]=n+1;
            for (int j=i;j<=maxn;j+=i)
            pri[j].push_back(i);
        }
    }
    for ( int i=1;i<=n+1;i++) F[i][0]=n+1;
    for ( int i = n ; i >= 1;i--)
    {
        F[i][0] = F[i+1][0];
        for ( int j : pri[a[i]])
        {
            F[i][0] = min ( F[i][0], nex[j]);
            nex[j]=i;
        }
    }

    for ( int i=1;i<=20;i++)
    {
        for ( int j=1;j<=n+1;j++)
            F[j][i]=F[F[j][i-1]][i-1];
    }
}
int main()
{
    read();
    solve();
    while(q--)
    {
        int l ,r ;
        cin >> l >> r ;
        int ans = 0;
        for ( int i=19;i>=0;i--)
        {
            if ( F[l][i] <= r )
            {
                l = F[l][i];
                ans += (1<<i);
            }
        }
        cout << ans + 1 << endl;
    }
    return 0;
}
