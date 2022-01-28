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
#define maxn 100111

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
int p[maxn];
vector<int> save[maxn];
int cnt[maxn];
int maxx = 0;
int n, k;
void solve(){
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> p[i];
        maxx = max(maxx, p[i]);
        for(int j=1;j<=p[i];j++)
        {
            int x;
            cin >> x;
            save[i].PB(x);
        }
    }
    for(int i=1;i<=n;i++)
    {
        while(save[i].size() != maxx) save[i].PB(50);
    }
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=0;j<save[i].size();j++)
//        {
//            cout << save[i][j] << " " ;
//        }
//        cout << endl;
//    }
    ll sum = 0;
    for(int i=0;i<maxx;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(save[j][i] >= sum || save[j][i] == 50)
            {
                k -- ;
                sum += 1ll*save[j][i];
                if ( k == 0 )
                {
                    cout << k * 50 + sum << endl;
                    return ;
                }
            }
        }
    }
    cout << k * 50 + sum << endl;
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



