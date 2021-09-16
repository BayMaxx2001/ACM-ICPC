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
#define maxn 5050

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

pll a[maxn];
ll F[maxn][maxn];
int n,k;
bool cmp( const pll &a , const pll &b)
{
    if(a.se == b.se) return a.fi < b.fi;
    return a.se < b.se;
}
void solve()
{
    cin >> n >> k;
    for(int i=1;i<=k;i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1,a+1+k,cmp);
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=n;j++)
            F[i][j]=1e18+1;
    }
    for(int i=0;i<=n;i++) F[0][i] = 0;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            F[i][j]=min(F[i][j-1], F[i-1][j-1] + a[i].se*(abs(a[i].fi-j)));
        }
    }
    cout << F[k][n];
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(NULL) ; cout.tie(NULL) ;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
    return 0;
}



