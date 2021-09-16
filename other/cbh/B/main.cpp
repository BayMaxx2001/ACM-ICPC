#include <bits/stdc++.h>
#define fi first
#define se second
#define mem0(BayMaxx)  memset(BayMaxx,0,sizeof(BayMaxx))
#define mem1(BayMaxx)  memset(BayMaxx,1,sizeof(BayMaxx))
#define mp make_pair
#define PB push_back
#define btcount(x) __builtin_popcount(x)
#define sqr(x) ((x) * (x))
#define INF 9999999999
#define MOD 1000000007
#define maxn 2000005

#define ull unsigned long long
#define uld unsigned long double
#define ld long double
#define ll long long


const long base = 151 ;
const ll MM = 1ll * MOD * MOD ;

using namespace std ;

typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

//---DEBUG
#define DB
#ifdef DB
#define el cerr << "\n";
    #define db(...) cerr << " [" << #__VA_ARGS__ << " : " << __VA_ARGS__ << "] ";
#else
#define el
#define db(...)
#endif // DB

// bit operater
int BIT(int i,ll x) { return(x&(1<<i));}
ll ONBIT(int i,ll x){ return(x|(1<<i));}
ll OFFBIT(int i,ll x){return (x& ~(1<<i));}
ll FLIPBIT(int i,ll x){return (x^(1<<i));}
// math
template<class T> T GCD(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T LCM(T a, T b) { return a / GCD(a, b) * b; }
// --I/O
#define BayMaxx ""
#define N 1000001
#define ONLINE_JUDGE
long long n, k, fc[N+1], rfc[N+1];
long long lt(long long x, long long y)
{
    long long ans= 1;
    for(long long i= x; y > 0; i= (i* i)% MOD)
    {
        if(y% 2== 1) ans= (ans* i)% MOD;
        y= y/ 2;
    }
    return ans;
}
void tinh()
{
    fc[0]= 1;
    for(long i= 1; i <= N; i++)
        fc[i]= ((long long)i* fc[i- 1])% MOD;
    rfc[N- 1]= lt(fc[N- 1], MOD- 2);
    for(long i= N- 2; i >= 0; i--)
        rfc[i]= ((long long)(i+ 1)* rfc[i+ 1])% MOD;
}
long long C(long long x, long long y)
{
    long long ans;
    ans= (fc[x+ y]* rfc[x])% MOD;
    ans= (ans* rfc[y])% MOD;
    return ans;
}
ll Ckn(ll k, ll n)
{
    return C(k,n-k);
}

void solve()
{
    int n;
    cin >> n;
    ll res = 0;
    for(int i=n/2;i<=n;i++)
    {
        int bit0 = i;
        int bit1 = n-i;
        res = (res + Ckn(bit1,bit0+1))%MOD;
    }
    ll ans = lt(2ll,n) - res;
    while ( ans < 0 ) ans += MOD;
    cout << ans << endl ;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(NULL) ; cout.tie(NULL) ;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int tc = 1;
    cin >> tc;
    tinh();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
    return 0;
}



