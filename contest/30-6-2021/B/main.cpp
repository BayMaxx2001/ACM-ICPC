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
#define maxn 1005

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
#define ONLINE_JUDGE

ll n, m, k;
ll a[maxn];
int dd[maxn];
ll sum[maxn];
ll F[maxn][maxn];
void solve()
{
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) dd[i]=0;
    for(int i=0;i<=1;i++)
    {
        for(int j=1;j<=m;j++) F[i][j]=0;
    }

    for(int i=1;i<=k;i++)
    {
        cin >> a[i];
        dd[a[i]+1]++;
    }
    for(int i=1;i<=m;i++) F[1][i] = 1;

    for( int i=2;i<=n;i++)
    {
        int oke = 0;
        if ( dd[i] == 1) oke = 1;
        for(int j=1;j<=m;j++) sum[j]=0;
        for(int j=1;j<=m;j++)
        {
            sum[j] = (sum[j-1]+F[i-1][j])%MOD;
            F[i][j] = (sum[j-1] + (F[i-1][j]*1ll*oke)%MOD)%MOD;
        }
    }

    ll ans = 0;
    for(int i=1;i<=m;i++)
        ans=(ans+F[n][i])%MOD;
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
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
    return 0;
}
