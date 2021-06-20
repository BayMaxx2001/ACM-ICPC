#include <bits/stdc++.h>
#define maxn 5000000
#define MOD 998244353
using namespace std;
long long F[maxn] ;
int n ;
int main()
{
    cin >> n ;
    for ( int i=1;i<=n;i++)
    {
        for( int j=i;j<=n;j+=i)
        {
            F[j] ++;
        }
    }
    F[1]=1;
    long long pre = 1;
    if ( n == 1 )
    {
        cout << 1 ;
        return 0;
    }
    for (int i=2;i<=n;i++)
    {
        F[i]=(F[i]+pre)%MOD;
        pre = (pre + F[i])%MOD;
    }
    cout << F[n] ;
}
