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
int Y(int n)
{
    if ( n==1) return 1;
    if ( n == 2 ) return 2;
    if ( n == 3 ) return 3;
    if ( n == 4) return 4;
    return Y(n-4) + X(n-3) + Y(n-2) + X(n-1);
}
int X(int n)
{
    if ( n==1) return 1;
    if ( n == 2 ) return 2;
    if ( n == 3 ) return 3;
    if ( n == 4) return 4;
    return X(n-4) + Y(n-3) + X(n-2) + Y(n-1);
}

void solve()
{
    cout << X(6) << " " << Y(7) << endl;
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



