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
int n , m ;
int a[maxn] ;
int b[maxn] ;
void nhap()
{
    //cin >> n ;
    scanf("%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++i)
        {
            scanf("%d" , &a[i] ) ;
            //cin >> a[i] ;
            b[i] = a[i] ;
        }
    sort ( b + 1 , b + 1 + n ) ;
    for ( long i = 1 ; i <= n ; ++i )
        a[i] = lower_bound( b + 1 , b + 1 + n , a[i] ) - b ;

}
int T[maxn] , F[maxn];
void Update( int x , int val )
{
    while ( x <= n )
    {
        T[x] = max ( T[x] , val )  ;
        x += ( x & (-x) ) ;
    }
}
int Get_max ( int x )
{
    int  S = 0 ;
    while ( x  > 0 )
    {
        S = max ( T[x] , S ) ;
        x -= ( x & (-x) ) ;
    }
    return S ;
}

int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(NULL) ; cout.tie(NULL) ;
    //freopen( ZED".inp" , "r" , stdin ) ;
    //freopen( ZED".out" , "w" , stdout ) ;
    nhap() ;
    int kq = 0 ;
    for ( int i = 1 ; i <= n ; ++i )
    {
        F[i] = Get_max(a[i] - 1) + 1 ;
        Update(a[i] , F[i] ) ;
        kq = max ( kq , F[i] ) ;
    }
    printf("%d" , kq ) ;

    return 0;
}


