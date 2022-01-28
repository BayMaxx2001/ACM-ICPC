#include <bits/stdc++.h>
#define maxn 1000001

#define ll long long
#define int long long
using namespace std;

long long n;
int ddr[maxn], ddc[maxn];
long long sum1(int n)
{
  return 1LL * n * (n + 1) / 2;
}

long long sum2(int l, int r)
{
  return sum1(r) - sum1(l - 1);
}

int sumr = 0, cntr = 0;
int sumc = 0, cntc = 0;
void row(int k)
{
    if ( ddr[k])
    {
        cout << 0 << endl ;
        return ;
    }
    ddr[k] = 1;
    ll ans = sum2(k+1,k+n);
    ll tru = sumc + cntc * k;
    sumr += k;
    cntr ++;
    cout << ans - tru << endl;
}
void col(int k)
{
    if( ddc[k] )
    {
        cout << 0 << endl;
        return;
    }
    ddc[k]=1;
    ll ans = sum2(k+1,k+n);
    ll tru = sumr + cntr * k;
    sumc += k;
    cntc ++;
    cout << ans - tru << endl;
}
main()
{
    int q;
    cin >> n >> q;
    while(q--)
    {
        char ch;
        int k;
        cin >> ch >> k;
        if(ch == 'R')
        {
           row(k);
        }
        else
        {
            col(k);
        }
    }
    return 0;
}
