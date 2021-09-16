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
//#define DB
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
#define int long long
int n , m , k;
typedef pair < long , pii > iii ;
iii a[maxn];
int root[maxn];
int add = MOD;
void read()
{
    cin >> n >> m >> k;
    add = MOD;
    for(int i=1;i<=n;i++) root[i]=0;
    for(int i=1;i<=m;i++)
    {
        int u , v , w; cin >> u >> v >> w;
        a[i] = (mp(w, mp(u,v)));
        add = min(add,abs(w-k));
    }
}
int find_set(int u) {
    return (root[u] > 0) ? root[u] = find_set(root[u]) : u ;
}
int min(int a, int b, int c)
{
    return min(a,min(b,c));
}
void solve()
{
    read();
    sort(a+1,a+1+m);
    int ans = 0;
    vector<int>list;
    for(int i=1;i<=m;i++)
    {
        int dd = a[i].fi;
        int u = a[i].se.fi ;
        int v = a[i].se.se ;
        int fu = find_set(u);
        int fv = find_set(v);
        if ( fu == fv ) continue;
        root[fu]=fv;
        db(dd);
        ans += max(0ll,dd-k);
    }
    if ( ans != 0 )
    {
        cout << ans << endl;
        return;
    }
    cout << add << endl;

}
main()
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



