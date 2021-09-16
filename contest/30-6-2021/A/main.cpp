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
#define maxn 500

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

int n , a[maxn];
int F[maxn][maxn];
bool cmp( const pii &a , const pii &b)
{
    return a.se < b.se;
}
bool process(vector < pii > v , int pivot, int X) {
    int j = pivot;
    int count = 0;
    for(int i=0;i<v.size();i++)
    {
        if ( j >n ) break;
        while( a[j]<=v[i].fi && j <= n)
            j++;
        if ( a[j] > v[i].fi && j <= n )
        {
            j++;
            count ++;
            if ( j >n ) break;
        }
    }
    return (count >= X);
}

bool check(long X){
    for(int pivot = 1;pivot<=n;pivot++)
    {
        if (pivot < X) continue;
        priority_queue<pii>heap;
        vector<pii>v;
        for(int i=1;i<=pivot;i++) heap.push(mp(-a[i],i));
        int count = 0 ;
        while(heap.size()){
            long res = -heap.top().fi;
            long id = heap.top().se;
            heap.pop();
            v.PB(mp(res,id));
            count ++ ;
            if ( count == X )
                break;
        }
        sort(v.begin(),v.end(),cmp);
        if ( process(v, pivot+1,X) == true ) return true;
    }
    return false;
}
void solve()
{
    int ans = 0;
    cin >> n;
    for(int i=1;i<=n;i++) cin >>a[i];
    for(int i=2;i+ans<=n;i++)
    {
        mem0(F);
        for(int j=1;j<i;j++)
        {
            for(int k=i;k<=n;k++)
            {
                F[j][k]= max(F[j-1][k], F[j][k-1]);
                if(a[j]<a[k])
                    F[j][k]=max(F[j][k], F[j-1][k-1]+1);
            }
        }
        ans = max(ans, F[i-1][n]);
    }
    cout << ans;

}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(NULL) ; cout.tie(NULL) ;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
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
