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
#define maxn 100005

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

int n,b[maxn],order[maxn];
int c[maxn];
int F[maxn][200];
pii a[maxn];
bool cmp(pii a,pii b)
{
    return a.fi<b.fi;
}
int pos(int x, int d, int y)
{
    int id = lower_bound(b+1,b+1+n,x)-b;
    if ( a[order[id]].fi+d == y )
        return order[id];
    return -1;
}
void solve()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i].fi;
        a[i].se = i;
        c[i]=a[i].fi;
    }
    sort (a+1,a+1+n);
    for(int i=1;i<=n;i++) b[i]=a[i].fi,order[i]=a[i].se;
    for(int i=1;i<=n;i++) a[i].fi=c[i];

    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=200;j++)
        {
            int z = pos(a[i].fi-j,j,a[i].fi);
            if ( z != -1 && z <= i)
            {
                F[i][j] = max(F[i][j], F[z][j]+1);
//                cout << a[z].fi << " " << j << " " << a[i].fi << endl;
            }
            ans = max(ans, F[i][j]);
        }
    }
    cout << ans+1;
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



