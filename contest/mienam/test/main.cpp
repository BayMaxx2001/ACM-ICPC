#include <bits/stdc++.h>
#define maxn 2000011
#define MOD 1000000007
#define int long long
using namespace std;

struct dataa
{
    int x, y;
}a[maxn];
int n;
bool cmpx(const dataa &u, const dataa &v)
{
    if ( u.x == v.x ) return u.y < v.y;
    return u.x < v.x;
}
bool cmpy(const dataa &u, const dataa &v)
{
    if ( u.y == v.y ) return u.x < v.x;
    return u.y < v.y;
}
bool cmpc(const dataa &u, const dataa &v)
{
    if ( u.x == v.x )
        return u.y < v.y;
    return u.x < v.x;
}

long long ansx = 0, ansy = 0, ansc = 0 ;
void read()
{
    cin >> n;
    for( int i=1;i<=n;i++)
    {
        cin >> a[i].x >> a[i].y;
    }


    a[n+1].x = a[n+1].y = a[0].x = a[0].y =  -1000000007;
    sort(a+1,a+1+n, cmpx);
    long long dem = 0;

    for(int i=1;i<=n+1;i++)
    {
        if(a[i].x != a[i-1].x)
        {
            ansx += 1ll*(dem*(dem-1))/2ll;
            dem = 1;
        }
        else
        {
            dem ++ ;
        }
    }

    sort(a+1,a+1+n, cmpy);
    dem = 0;

    for(int i=1;i<=n+1;i++)
    {
        if(a[i].y != a[i-1].y )
        {
            ansy += 1ll*(dem*(dem-1))/2ll;
            dem = 1;
        }
        else
        {
            dem ++ ;
        }
    }

    sort(a+1,a+1+n, cmpc);
    dem = 0;

    for(int i=1;i<=n+1;i++)
    {
        if(a[i].y == a[i-1].y && a[i].x == a[i-1].x )
        {
            dem ++;
        }
        else
        {
            ansc += 1ll*(dem*(dem-1))/2ll;
            dem = 1;
        }
    }
    cout << ansx + ansy - ansc ;
}
main()
{
    read();
}
