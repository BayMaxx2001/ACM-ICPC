#include <bits/stdc++.h>
#define PB push_back
#define maxn 1000500
#define INF 999999999
#define int long long
using namespace std;
vector<int> a[maxn] ;
int n, m ;
void read()
{
    cin >> n >> m;
    for(int i=1; i<=m; i++)
    {
        int x, y;
        cin >> x >> y;
        x -- , y --;
        a[x].PB(y);
        a[y].PB(x);
    }
}
bool av[maxn];
long h[maxn] ;
int maxxtree = 0;
int lasttree = 1;
int dem = 0;
void BFS()
{
    vector<int> dist (n, INF);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        dem++;
        for (int v : a[u])
            if (dist[v] == INF)
            {
                maxxtree = dist[v] = dist[u] + 1;
                q.push(v);
            }
    }
}
void solve()
{
    BFS();
    if ( dem < n)
    {
        cout << -1 ;
        return ;
    }
    cout << ceil(log(maxxtree)/log(2))+1 << endl;
}
main()
{
    read();
    solve();
    return 0;
}
