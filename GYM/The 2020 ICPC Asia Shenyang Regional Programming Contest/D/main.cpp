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

int n, ans = 0;
string s="";
int sum[20];

string bin(int dec, int length)
{
    string s = "";
    while(dec)
    {
        int k = dec%2;
        if ( k == 0 ) s = s + "0";
        else s = s + "1";
        dec = dec/2;
    }
    reverse(s.begin(),s.end());
    while (s.size()!=length)
        s = "0" + s;
    return s;
}
int calc(string s)
{
    int res = 0;
    for(int i=0;i<s.size();i++) sum[i]=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == '1') sum[i]=sum[i-1]+1;
        else sum[i] = sum[i-1];
    }
    for(int i=0;i<s.size();i++)
    {
        for(int j=i;j<s.size();j++)
        {
            if((sum[j]-sum[i-1])%2) res++;
        }
    }
    return res;

    for(int i=0;i<s.size();i++)
    {
        for(int j=i;j<s.size();j++)
        {
            int dem = 0;
            for(int k=i;k<=j;k++)
            {
                if(s[k] == '1') dem++;
            }
            //cout << i << " " << j << " " << dem << endl;
            if ( dem % 2 ) res ++ ;
        }
    }
    return res;
}
typedef pair < int, string> pis;
vector<pis> save;
string output(string str){
    string res = "";
    for(int i=0;i<str.size();i++)
    {
        if(str[i] == '0') res = res + "b";
        else res = res + "r";
    }
    return res;
}
void trace(int length)
{
    for(ll i=1;i<pow(2,length);i++)
    {
        string str = bin(i,length);
        if ( calc(str) == ans )
        {
            int sl = __builtin_popcountll(i);
            save.PB(mp(sl,str));
            if(save.size() == 100 )
                break;
            //cout << str << " " << i << endl ;
        }
    }
    //sort(save.begin(),save.end());
    for(int i=0;i<save.size();i++)
    {
        //cout << save[i].se << endl;
        //cout << output(save[i].se) << endl ;
        cout << save[i].fi << " " << save[i].se << " " << "count: " << i + 1 << endl;
    }
}
void solve()
{
    cin >> n;
    for(int i=1;i<=n;i+=2)
    {
        ans += ( n - i ) + 1;
    }
    cout << ans << endl ;
    trace(n);
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



