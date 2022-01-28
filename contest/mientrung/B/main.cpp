#include <bits/stdc++.h>
#define maxn 100005
#define MOD 1000000007
#define int long long
#define PB push_back
using namespace std;
int n;
long long a[maxn];
vector<long long> am;
vector<long long> duong;
int dem0 = 0;
void read()
{
    cin >> n;
    long long ans = 1ll;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if ( a[i] < 0 )
        {
            am.PB(a[i]);
        }
        if ( a[i] == 0 )
            dem0++;
        if ( a[i] > 0 )
        {
            duong.PB(a[i]);
        }
    }
    sort(am.begin(),am.end());
    sort(duong.begin(), duong.end());
    if ( dem0 > 1 )
    {
        cout << 0;
        return;
    }
    if ( dem0 == 0 )
    {
        int slam = am.size();
        if ( slam % 2 == 0 )
        {
            for(int i=1;i<=n;i++)
            {
                ans = ( ans * a[i] ) % MOD;
            }
            cout << ans % MOD ;
            return ;
        }
        if ( slam % 2 )
        {
            for(int i=0;i<am.size()-1;i++)
            {
                ans = ( ans * am[i] ) % MOD;
            }
            for(int i=0;i<duong.size();i++)
            {
                ans = ( ans * duong[i]) % MOD;
            }
            cout << ans % MOD;
            return;
        }
    }
    if ( dem0 == 1 )
    {
        int slam = am.size();
        if ( slam % 2 == 0 )
        {
            for(int i=1;i<=n;i++)
            {
                if ( a[i] == 0 ) continue;
                ans = ( ans * a[i] ) % MOD;
            }
            cout << ans % MOD ;
            return ;
        }
        else
        {
            cout << 0 ;
            return;
        }
    }
}
 main()
{
    read();
}
