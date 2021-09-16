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
int BIT(int i,ll x)
{
    return(x&(1<<i));
}
ll ONBIT(int i,ll x)
{
    return(x|(1<<i));
}
ll OFFBIT(int i,ll x)
{
    return (x& ~(1<<i));
}
ll FLIPBIT(int i,ll x)
{
    return (x^(1<<i));
}
// math
template<class T> T GCD(T a, T b)
{
    T r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
template<class T> T LCM(T a, T b)
{
    return a / GCD(a, b) * b;
}
// --I/O
#define BayMaxx ""
#define ONLINE_JUDGE
ll dp[30];
vector < ll > save;
vector < ll > mu;
int cnt[30];
void gen()
{
    dp[1]=1;
    for(ll i=2;i<=20;i++)
        dp[i]=dp[i-1]*i;
}

void Init(ll n )
{
    mem0(cnt);
    save.clear();
    mu.clear();
    ll div = 2;
    ll x = n ;
    while ( n > 0 ) {
        mu.PB(div);
        save.PB(n%div);
        n /= div ;
        div ++ ;
    }
    n = x ;
    sort(save.begin(),save.end());
    for(int i=0;i<save.size();i++)
    {
        cnt[save[i]]++;
    }
}
ll  sol1(){
    ll pro = 1ll;
    for (ll i=0;i<mu.size();i++)
    {
        ll dev = mu[i];
        int dem = 0;
        for(ll j=0;j<save.size();j++)
        {
            int val = save[j];
            if ( val < dev )
                dem++;
        }
        pro=pro*1ll*(dem-i);
    }

    for(int i=0;i<=20;i++)
    {
        if(cnt[i]==0) continue;
        pro = 1ll* pro/dp[cnt[i]];
    }
    return pro;
}

ll sol2(){
    ll res = 1ll;
    for (ll i=0;i<mu.size()-1;i++)
    {
        ll dev = mu[i];
        int dem = 0;
        for(ll j=1;j<save.size();j++)
        {
            int val = save[j];
            if ( val < dev )
                dem++;
        }
        res=res*1ll*(dem-i);
    }
    cnt[save[0]]--;
    for(int i=0;i<=20;i++)
    {
        if(cnt[i]==0) continue;
        res = 1ll* res/dp[cnt[i]];
    }
    return res;
}
void solve()
{
    ll n;
    cin >> n;
    Init(n);
    if ( save[0] != 0 )
    {
        cout << sol1() - 1 << endl;
        return ;
    }
    cout << sol1() - sol2() - 1 << endl;
}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(NULL) ;
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    gen();
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t  << ": ";
        solve();
    }
    return 0;
}



