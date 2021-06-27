#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll c[500][500];
ll n , mod ;
ll mu[500] ;
ll F[500][500];
ll solve()
{
    for(int i=0;i<410;i++)
    {
        for(int j=0;j<=i;j++){
            if ( j == 0 ) c[i][j]=1;
            else
                c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }

    mu[0]=1;
    for( int i=1;i<=500;i++)
    {
        mu[i]=(mu[i-1]*2ll)%mod;
    }

    F[1][1] = 1;
    for ( int i=1;i<=n;i++)
    {
        F[i][i] = mu[i-1];
        for( int j=1;j<i;j++)
        {
            for( int k=1;k<j;k++)
            {
                F[i][j] = F[i][j]+((F[i-k-1][j-k]*c[j][k])%mod * mu[k-1])%mod;
                F[i][j] = F[i][j]%mod;
            }
        }
    }
    int ans = 0;
    for( int i=1;i<=n;i++)
        ans = (ans + F[n][i])%mod;

    return ans ;

}
int main()
{
    cin >> n >> mod;
    cout << solve();
    return 0;
}
