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
string s;
int sx[5] = {1,-1,0,0}; // U , D , L , R
int sy[5] = {0,0,-1,1};
void solve()
{
    vector <pii> path;
    cin >> s ;
    int x = 0 , y = 0;
    for( int i=0;i<s.size();i++)
    {
        if ( s[i] == 'U') { x += sx[0], y += sy[0] ;}
        if ( s[i] == 'D') { x += sx[1], y += sy[1] ;}
        if ( s[i] == 'L') { x += sx[2], y += sy[2] ;}
        if ( s[i] == 'R') { x += sx[3], y += sy[3] ;}
        path.PB(mp(x,y));
    }

    for( auto p:path){
        int dx = 0, dy = 0;
        for(int i=0;i<s.size();i++){
            pii t;
            t.fi = dx;
            t.se = dy;
            if ( s[i] == 'U') { t.fi += sx[0], t.se += sy[0] ;}
            if ( s[i] == 'D') { t.fi += sx[1], t.se += sy[1] ;}
            if ( s[i] == 'L') { t.fi += sx[2], t.se += sy[2] ;}
            if ( s[i] == 'R') { t.fi += sx[3], t.se += sy[3] ;}
            if ( p != t )
            {
                dx=t.fi;
                dy=t.se;
            }
        }
        if ( dx == 0 && dy == 0 ) {
            cout << p.se << " " << p.fi << endl;
            return;
        }
    }
    cout << 0 << " " << 0 << endl ;
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



