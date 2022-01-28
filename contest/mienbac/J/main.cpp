#include <bits/stdc++.h>
#define maxn 1000001
#define int long long
using namespace std;

int n, m;
struct da{
    int gt;
    int ngay;
}a[maxn];
bool check(int num)
{
    int dem = 0ll;
    for(int i=1;i<=n;i++)
    {
        int du = num % (a[i].ngay + 1ll);
        int sl = num /(a[i].ngay+1ll);
        dem += sl * a[i].gt * a[i].ngay ;
        if ( du < a[i].ngay )
        {
            dem += du * a[i].gt;
        }
        else
        {
            dem += a[i].gt * a[i].ngay ;
        }
    }

    return ( dem >= m );
}
main()
{
    cin >> n >> m ;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i].gt >> a[i].ngay;
    }
    int l = 0, r = 1000000000000000009;
    while (r - l > 1 )
    {
        int mid = (l + r)/2;
        if ( check(mid) )
        {
            r = mid;
        }
        else l = mid;
    }
    cout << r;
}
