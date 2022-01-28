#include <bits/stdc++.h>
#define maxn 1000001
#define int long long
using namespace std;

int n;
int ass , en ;

struct val{
    int id;
    int dist;
}a[maxn];
bool cmp ( const val &u, const val &v)
{
    if ( u.dist == v.dist) return u.id < v.id;
    return u.dist < v.dist;
}

main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i].id;
    }
    cin >> ass;
    cin >> en;
    for(int i=1;i<=n;i++)
    {
        a[i].dist = abs(a[i].id - en ) ;
    }
    sort(a+1,a+1+n,cmp);

//    for(int i=1; i<=n;i++)
//    {
//        cout << a[i].id << " " << a[i].dist << endl;
//    }
    long long sum = 0;
    for(int i=1;i<=n;i++)
    {
        sum += 1ll*a[i].dist;
        if ( sum >= abs(ass - en) )
        {
            cout << i - 1 ;
            return 0 ;
        }
    }
    cout << n ;
    return 0;
}
