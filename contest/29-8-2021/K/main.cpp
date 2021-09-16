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
#define maxn 300010

#define ull unsigned long long
#define uld unsigned long double
#define ld long double
#define ll long long
#define int long long

const long base = 71 ;
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
#define N 300001
string a;
long long H[N],M[N];
int n;
int id;
void hash_build(string a, int n) {
    for (int i = 1; i <= n; i++)
        H[i] = (H[i - 1] * base + a[i] - 'a') % MOD;
}

long long hash_range( int L, int R) {
    return (1ll*H[R] - H[L - 1] * M[R - L + 1] + 1LL * MOD * MOD) % MOD;
}

int save[N];
bool check( int mid )
{
    int top = 0;
    for(int i = 1; i<= n-mid+1; i ++)
    {
        ll x = hash_range(i,i+mid-1);
        save[++top] = x;
    }
    sort (save+1, save+top+1);
    save[top+1]=save[0] = -1;
    for(int i=1;i<=top;i++)
        if (save[i]!=save[i-1] && save[i]!=save[i+1])
            return 1;
    return 0;
}
pii ans[N];
void output(int len)
{
    int top = 0;
    ans[top].fi = -1;
    for(int i = 1; i<= n-len+1; i ++)
    {
        ll x = hash_range(i,i+len-1);
        ans[++top] = {x,i};
    }
    sort (ans+1, ans+top+1);
    save[top+1]=save[0] = -1;
    int pos=MOD;
    for(int i=1;i<=top;i++)
        if (ans[i].fi!=ans[i-1].fi && ans[i].fi!=ans[i+1].fi)
            pos=min(pos, ans[i].se);
//    cout << pos << endl;
    for(int i=1;i<=len;i++)
        cout << a[pos+i-1];
}
void solve()
{
    M[0] = 1ll;
    cin >> a;
    n = a.size();
    if ( n == 1 )
    {
        cout << a ;
        return;
    }

    a = " " + a;
    for (int i = 1; i < n; i++)
        M[i] = M[i - 1] * base % MOD;
    hash_build(a,n);

    int l=0, r=n;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (check(mid)) r=mid;
        else l=mid;
    }
//    cout << r << endl ;
    output(r);
}
main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(NULL) ; cout.tie(NULL) ;
    #ifndef ONLINE_JUDGE
        freopen(".inp", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
    return 0;
}



