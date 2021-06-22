#include <bits/stdc++.h>
#define PB push_back
using namespace std;
vector < long > a[maxn];
int n , k ;

void read()
{
    cin >> n >> k ;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> x ;
        a[i+1].PB(x);
        a[x].PB(i+1);
    }
}
void DFS(int u)
{
    for(v :a[i])
    {
        h[v]=h[u]+1;
        DFS(v);
    }
}
void solve()
{
    h[1]=1;
    DFS(1);
}
int main()
{

    return 0;
}
