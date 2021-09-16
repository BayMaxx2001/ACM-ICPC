#include <bits/stdc++.h>
#define fi first
#define se second
#define mem0(BayMaxx)  memset(BayMaxx,0,sizeof(BayMaxx))
#define mem1(BayMaxx)  memset(BayMaxx,1,sizeof(BayMaxx))
#define mp make_pair
#define PB push_back
#define btcount(x) __builtin_popcount(x)
#define sqr(x) ((x) * (x))
#define MOD 1000000007
#define maxn 2000005

#define ull unsigned long long
#define uld unsigned long double
#define ld long double
#define ll long long

#define rep(i, n) for(int i = 0; i < n; i++)
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
#define BayMaxx ""
//#define ONLINE_JUDGE

#define maxn 1011

struct edge
{
	int x, y, cap, flow;
};

struct Flow
{
	int n, S, T;
	vector < vector <int> > a;
	vector <int> cur, d;
	vector <edge> e;

	Flow() {}
	Flow(int _n, int _S, int _T)
	{
		n = _n; S = _S; T = _T;
		a = vector < vector <int> >(n + 1);
		cur = vector <int>(n + 1);
		d = vector <int>(n + 1);
	}

	void addEdge(int x, int y, int _cap)
	{
		edge e1 = {x, y, _cap, 0};
		edge e2 = {y, x, _cap, 0};
		a[x].push_back(e.size()); e.push_back(e1);
		a[y].push_back(e.size()); e.push_back(e2);
	}

	int bfs()
	{
		queue <int> q;
		for (int i = 1; i <= n; i++) d[i] = -1;
		q.push(S); d[S] = 0;
		while (!q.empty() && d[T] < 0)
		{
			int x = q.front(); q.pop();
			for (int i = 0; i < int(a[x].size()); i++)
			{
				int id = a[x][i], y = e[id].y;
				if (d[y] < 0 && e[id].flow < e[id].cap)
					q.push(y), d[y] = d[x] + 1;
			}
		}
		return d[T] >= 0;
	}

	int dfs(int x, int val)
	{
		if (!val) return 0;
		if (x == T) return val;
		for (; cur[x] < int(a[x].size()); cur[x]++)
		{
			int id = a[x][cur[x]], y = e[id].y;
			if (d[y] != d[x] + 1) continue;
			int pushed = dfs(y, min(val, e[id].cap - e[id].flow));
			if (pushed)
			{
				e[id].flow += pushed;
				e[id ^ 1].flow -= pushed;
				return pushed;
			}
		}
		return 0;
	}

	int maxFlow()
	{
		int res = 0;
		while (bfs())
		{
			for (int i = 1; i <= n; i++) cur[i] = 0;
			while (1)
			{
				int val = dfs(S, MOD);
				if (!val) break;
				res += val;
			}
		}
		return res;
	}
};

int number(string s)
{
    stringstream ss(s);
    int x;
    ss >> x;
    return x;
}
vector <pii> save;
void solve()
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        int ans = MOD;
        for (int i = 1; i <= m; i++)
        {
            int p, q;
            scanf(" (%d,%d)", &p, &q);
            p++;
            q++;
            save.PB(mp(p,q));
        }
        if ( n == 1 || n == 0 )
        {
            printf("0\n");
            continue;
        }
        if ( n == 2 )
        {
            printf("%d\n",m);
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                Flow u(n,i,j);
                for(int k = 0;k<save.size();k++)
                {
                    u.addEdge(save[k].fi, save[k].se, 1 );
                }
                printf("%d %d %d\n", i , j, u.maxFlow());
                ans = min ( ans , u.maxFlow());
            }
        }
        printf("%lld",ans);
        printf("-------------\n");
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t  << ": ";
        solve();
    }
    return 0;
}



