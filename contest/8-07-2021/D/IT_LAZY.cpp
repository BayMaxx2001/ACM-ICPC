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
int n, S;
ll a[maxn];
const int MAXN = 100111;
struct Node {
    int lazy; // giá trị T trong phân tích trên
    int val; // giá trị lớn nhất
} nodes[MAXN * 4];

void down(int id) {
    int t = nodes[id].lazy;
    nodes[id*2].lazy += t;
    nodes[id*2].val += t;
    nodes[id*2+1].lazy += t;
    nodes[id*2+1].val += t;
    nodes[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    if (v < l || r < u) {
        return ;
    }
    if (u <= l && r <= v) {
        nodes[id].val += val;
        nodes[id].lazy += val;
        return ;
    }
    int mid = (l + r) / 2;

    down(id);
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);

    nodes[id].val = min(nodes[id*2].val, nodes[id*2+1].val);
}

int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return -2000111000;
    }
    if (u <= l && r <= v) {
        return nodes[id].val;
    }
    int mid = (l + r) / 2;
    down(id);

    return min(get(id*2, l, mid, u, v),
        get(id*2+1, mid+1, r, u, v));
}

void test(){
    int n, q; cin >> n >> q;
    while (q--) {
        int typ; cin >> typ;
        if (typ == 0) {
            int l, r, val; cin >> l >> r >> val;
            update(1, 1, n, l, r, val);
        }
        else {
            int l, r; cin >> l >> r;
            printf("%d\n", get(1, 1, n, l, r));
        }
    }
}
void solve()
{
    ll ans = -MOD;
    cin >> n >> S;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
        update(1,1,n,i,i,a[i]);
    for(int i=1;i<=n;i++)
    {
        if ( i == 1) {
            update(1,1,n,1,1,S*(n-i));
            update(1,1,n,2,n,(-S));
            ans = max(ans,get(1,1,n,1,n));
        }
        else {
            update(1,1,n,1,i-1,-S);
            update(1,1,n,i,i,S*(n-1));
            update(1,1,n,i+1,n,-S);
            ans = max(ans,get(1,1,n,1,n));
        }
//        cout << get(1,1,n,1,n) << " ";
    }
    cout << ans;
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



