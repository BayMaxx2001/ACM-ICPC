#include <bits/stdc++.h>
#define maxn 1000005
#define PB push_back
#define int long long
using namespace std;
vector<int>ans;
int n, d ;
int a[maxn];
int pre[maxn][20];
void read()
{
    cin >> n >> d;
    for( int i=1;i<=n;i++ )
    {
        cin >> a[i];
    }
    memset(pre,-1,sizeof(pre));
}

double  F[maxn][20];
void solve()
{
    for(int j=0;j<=9;j++) F[0][j]=-1e9;
    F[0][1]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=9;j++) F[i][j]=F[i-1][j];
        for(int j=0;j<=9;j++)
        {
            int k = j *a[i]%10;
            if (a[i]==1 || F[i][k]<F[i-1][j]+log2(a[i]))
            {
				F[i][k]=F[i-1][j]+log2(a[i]);
				pre[i][k]=j;
			}
        }
    }
    if ( F[n][d] < 0 )
    {
        cout << -1;
        return;
    }
    for (int i=n;i>=1;i--)
    {
        if ( pre[i][d]!= -1)
        {
            ans.PB(a[i]);
            d = pre[i][d];
        }
    }
    if (ans.size()== 0)
    {
        cout << -1 ;
        return ;
    }
    cout << ans.size() << endl;
    for( auto x : ans)
    {
        cout << x << " ";
    }
}
main()
{
    read();
    solve();
    return 0;
}
