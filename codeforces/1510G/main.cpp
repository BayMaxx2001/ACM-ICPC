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
#define maxn 1005

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
int n, k ;
vector < int > a[maxn];
vector < int > ans , path(maxn,false);
int av[maxn] ;
int dept[maxn];
int parent[maxn];
void DFS_best(int u)
{
    av[u]=false;
    for(int i=0;i<a[u].size();i++)
    {
        int v = a[u][i];
        av[v] = true;
        dept[v]=dept[u]+1;
        DFS_best(v);
    }
}

void DFS(int u)
{
    ans.PB(u);
    for( int v:a[u])
    {
        if ( av[v] && path[v] == false )
        {
            DFS(v);
            ans.PB(u);
        }
    }
    for( int v : a[u])
    {
        if ( path[v] == true)
        {
            DFS(v);
        }
    }
}
void solve()
{
    cin >> n >> k;
    for(int i=0;i<=n;i++) a[i].clear(), dept[i]=0, parent[i]=0;
    ans.clear();
    for(int i=2;i<=n;i++)
    {
        int x;cin>>x;
        parent[i]=x;
        a[x].PB(i);
    }
    mem0(av);
    DFS_best(1);
    int best = 0;
    int pivot = 1;
    for(int i=1;i<=n;i++)
    {
        if (dept[i] >= best)
        {
            best = dept[i];
            pivot = i;
        }
    }
    path.clear();
    for(int i=0;i<=n;i++ ) path[i]=false;
    mem0(av);
    while(pivot!=0)
    {
        ans.PB(pivot);
        path[pivot] = true;
        av[pivot] = true;
        pivot = parent[pivot];
    }
//    for(int i=0;i<ans.size();i++) cout << ans[i] << " " ;

    int cnt = k - best - 1;
    if ( cnt <= 0 )
    {
        int count = 0;
        cout << k - 1 << endl;
        for(int i = ans.size()-1;i>=0;i--)
        {
            count ++;
            cout << ans[i] << " " ;
            if ( count == k )
            {
//                cout <<  "###" << endl;
                return;
            }
        }
    }
    ans.clear();
    for(int i=1;i<=n;i++)
    {
        if(av[i]==false && cnt)
        {
            cnt --;
            av[i]= true;
        }
    }
    DFS(1);
    cout << ans.size() - 1<< endl;
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << " " ;
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



