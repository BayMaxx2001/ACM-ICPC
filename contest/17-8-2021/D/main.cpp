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
#define ONLINE_JUDGE
#define int long long
ll n,m,A,B;
vector < pll > a[maxn];
ll d[maxn];
ll half = 0;
void dijsktra(ll s )
{
    priority_queue<pll>hmin;
    for ( int i=0;i<=n;i++) d[i] = MOD;
    d[s]=0;
    hmin.push(mp(d[s],s));
    while(hmin.size())
    {
        int u = hmin.top().se;
        int dist = -hmin.top().fi;
        hmin.pop();
        for(auto &ke : a[u])
        {
            int v = ke.fi;
            int w = ke.se;
            if ( d[v] > dist + w)
            {
                d[v]=dist+w;
                hmin.push ( mp(-d[v] , v ) );
            }
        }
    }
}
map<pii,int> M;
void solve()
{
    cin >> n >> m >> A >> B;
    half = B/2;
    for ( int i=1;i<=m;i++)
    {
        int u, v , w;
        cin >> u >> v >> w;
        a[u].PB(mp(v,w));
        a[v].PB(mp(u,w));
    }
    dijsktra(0);
    for(int i=1;i<=n;i++)
    {
        db(d[i]) ;
        cout << " ";
    }
    cout << endl;
    int ans = 0;
    for(int i=0;i<=n;i++)
    {
        for( int j = 0; j <a[i].size();j ++)
        {
            int u = i;
            int v = a[i][j].fi;
            int w = a[i][j].se;
            db(u);
            db(v);
            db(d[u]);
            db(w);
            cout << endl;
            pii street = {u,v};
            pii street2 = {v,u};
            if ( d[u] <= half )
            {
                if ( M[street] == 0 || M[street2] == 0 )
                {
                    ans ++;
                    M[street] = 1;
                    M[street2] =1;
                }
            }
        }
    }
    cout << ans ;

}
main()
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



