#include <bits/stdc++.h>
#define maxn 500004
using namespace std;
int n , a[maxn];
int b[maxn];
int pre[maxn] , last[maxn];
void read()
{
    cin >> n;
    for( int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
}
bool check( int dau, int mid, int mid2, int cuoi)
{
    int k = dau - mid;
    int k1 = mid2 - cuoi;
    if ( k + k1 == 0 && mid2 >= cuoi ) return true;
    return false;
}
void solve()
{
    bool oke = true ;
    memset(pre,0,sizeof(pre));
    memset(last,0,sizeof(last));
    pre[0]= last[n+1]=0;
    for(int i=1;i<=n;i++)
    {
        pre[i] = a[i]-pre[i-1];
        pre[i] = pre[i-1]<0 ? -1: pre[i];
    }
    for(int i=n;i>=1;i--)
    {
        last[i] = a[i] - last[i + 1];
        last[i] = last[i + 1] < 0 ? -1 : last[i];
    }
    if ( pre[n]) oke = false;
    if ( oke )
    {
        cout << "YES" << endl;
        return;
    }
    if ( n == 1 ){
        cout << "NO" << endl;
        return;
    }
    if ( n == 2) {
        if ( a[1] == a[2] ) cout << "YES" << endl;
        else cout <<"NO"<<endl;
        return ;
    }
    for(int i=1;i<n;i++)
    {
        if ( last[i+2] < 0 || pre[i-1] < 0 ) continue;
        if ( check(last[i+2],a[i],a[i+1],pre[i-1]) )
        {
            oke = true;
        }
    }
    if ( oke ) {
        cout << "YES" << endl;
    }
    else
        cout <<"NO"<<endl;
    return;
}
int main()
{
    int te ;
    cin >> te;
    while (te--){
        read();
        solve();
    }
    return 0;
}
