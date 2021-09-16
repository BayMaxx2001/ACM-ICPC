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
int n;
int a[maxn], origin[maxn];

int check( int a[])
{
    int oke = 0;
    for(int i=1;i<=n;i++)
    {
        if (a[i] != origin[i])
        {
            oke = 1;
            break;
        }
    }
    if ( oke == 0 ) return -1;
    for(int i=1;i<=n;i++)
    {
        if ( a[i]-a[i-1] != 1 )
            return 0;
    }
    return 1;
    for(int i=1;i<=n;i++)
        cout << a[i] << " ";
}
int calc(int cur)
{
    int k = n*3;
    int count = 0;
    bool oke = 0;
    for(int i=1;i<=n;i++)
    {
        if ( a[i]-a[i-1] != 1 )
        {
            oke = 1;
            break;
        }
    }
    if ( oke == 0 )
        return 0;
    while (k -- )
    {
        cur = 1-cur;
        count ++;
        if ( cur == 1 )
        {
            for(int i=1;i<=n;i+=2)
            {
                swap(a[i],a[i+1]);
            }
            int res = check(a);
            if ( res == 1 )
            {
                return count ;
            }
            if ( res == -1)
                return -1;
        }
        if ( cur == 0 )
        {
            for(int i=1;i<=n/2;i++)
            {
                swap(a[i],a[n/2+i]);
            }
            int res = check(a);
            if ( res == 1 )
            {
                return count ;
            }
            if ( res == -1)
                return -1;
        }
    }
}
void solve()
{
    cin >> n;
    n = n * 2;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) origin[i] = a[i];
    int ans1 = calc(1);
    for(int i=1;i<=n;i++) a[i] = origin[i];
    int ans2 = calc(0);
    if ( ans1 == -1 || ans2 == -1)
        cout <<  max(ans1, ans2);
    else
        cout << min(ans1,ans2);
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



