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

long long a, b, c, d;
map < pll, int > M;

pll rutgon(ll tu, ll mau){
    long long gcd = GCD(tu,mau);
    tu /= gcd;
    mau /= gcd;

    pll a = {tu,mau};
    return a;
}
ll check( ll tu, ll mau, ll a, ll b, ll c, ll d){
    ll topL = ceil ((double)a/tu);
    ll topR = floor((double)b/tu);
    ll botL = ceil ((double)c/mau);
    ll botR = floor((double)d/mau);
    if( topR < botL )
        return 0;
    if ( botR < topL )
        return 0;
    db(tu);
    db(mau);
    db(topL);
    db(topR);
    db(botL);
    db(botR);
    db(min(topR,botR) - max(topL, botL)+1);
//    cout << endl;
    return min(topR,botR) - max(topL, botL)+1;
}
void solve()
{
    cin >> a >> b >> c >> d;
    ll ans = 0;
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=1000;j++)
        {
            if(i+j >= 1000) continue;
            if ( i > b || j > d ) continue;
            pll cur = rutgon(i,j);
            if(M[cur] == 1 ) continue;
            M[cur]=1;
            ans += check(i,j,a,b,c,d);

        }
    }
    cout << ans ;
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



