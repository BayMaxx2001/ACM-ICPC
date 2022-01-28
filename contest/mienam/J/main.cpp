#include <bits/stdc++.h>
#define maxn 5005
using namespace std;

int n, m ;
int a[maxn][maxn];
int l[maxn][maxn];
int r[maxn][maxn];
int u[maxn][maxn];
int d[maxn][maxn];
int minn( int u, int v, int x, int y)
{
    return std::min({x, y, u, v });
}
int main()
{
    cin >> n >> m;
    bool only = false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char x;
            cin >> x;
            if ( x == '0' ) a[i][j] = 0;
            else a[i][j] = 1;
            if ( a[i][j] == 1 )
            {
                only = true;
            }
        }
    }
    if ( only == false)
    {
        cout << "-1" ;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j] == 0)
            {
                l[i][j] = 0;
                u[i][j] = 0;
            }
            else
            {

                l[i][j] = l[i][j-1] + 1;
                u[i][j] = u[i-1][j] + 1;
            }
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=1;j--)
        {
            if(a[i][j] == 0)
            {
                r[i][j] = 0;
                d[i][j] = 0;
            }
            else
            {
                r[i][j] = r[i][j+1] + 1;
                d[i][j] = d[i+1][j] + 1;
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if ( a[i][j] == 0 ) continue;
            int up = u[i-1][j];
            int down = d[i+1][j];
            int left  = l[i][j-1];
            int righ = r[i][j+1];

            int k = minn(up, down, left, righ);
            ans = max (ans, k);
        }
    }

    if ( ans == 0 )
    {
        cout << 1 << endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if (a[i][j] == 1)
                {
                    cout << i << " " << j ;
                    return 0;
                }
            }
        }
    }
    cout << ans * 4 + 1 << endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if ( a[i][j] == 0 ) continue;
            int up = u[i-1][j];
            int down = d[i+1][j];
            int left  = l[i][j-1];
            int righ = r[i][j+1];

            int k = minn(up, down, left, righ);
            if ( ans == k )
            {
                cout << i <<  " " << j;
                return 0;
            }
        }
    }
    return 0;
}
