#include <bits/stdc++.h>
#define maxn 100005
#define MOD 1000000007
#define int long long
#define PB push_back
using namespace std;
int n, m;
vector<int> a[maxn];
int av[maxn];
int dem = 0;
void DFS(int u)
{
    dem ++ ;
    av[u]=true;
    for(int i=0;i<a[u].size();i++)
    {
        int v = a[u][i];
        if ( av[v] == false )
        {
            DFS(v);
        }
    }
}
long long calc(long long dem)
{
    long long gt = 1ll;
    for(int i=1;i<=dem;i++)
    {
        gt = (gt *1ll*i)%MOD;
    }
    return gt % MOD;
}
main()
{
    int tong = 0;
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int x, y;
        cin >> x >> y;
        x++;y++;
        a[x].PB(y);
        a[y].PB(x);
    }
    long long ans = 0;
    for(int i=1;i<=n;i++)
    {
        if ( av[i] == false )
        {
            dem = 0;
            DFS(i);
            if ( dem > 2 )
                ans = (ans + calc(dem))%MOD;
            tong += dem;
        }
        if ( tong >= dem ) break;
    }
    cout << ans ;

}
