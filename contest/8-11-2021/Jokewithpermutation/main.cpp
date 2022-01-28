#include <bits/stdc++.h>

#define maxn 51
#define PB push_back
using namespace std;

int C[maxn];
string s;
bool vis[maxn];
int n;
deque<int>f;
int len;

int pt(int x)
{
    int cnt = 0;
    while(x)
    {
        cnt++;
        x /= 10;
    }
    return cnt;
}

void init()
{
    memset(C, 0, sizeof C);
    for(int i = 1; i <= 50; i++)
        C[i] = C[i - 1] + pt(i);
}

bool dfs(int p)
{
    if(p == len) return true;
    int x;
    x = s[p]- '0';
    if(x <= n && !vis[x])
    {
        f.PB(x);
        vis[x] = true;
        if(dfs(p + 1)) return true;
        f.pop_back();
        vis[x] = false;
    }
    if(p + 1 < len)
    {
        x = (s[p] - '0') * 10 + s[p + 1] - '0';
        if(x <= n && !vis[x])
        {
            f.PB(x);
            vis[x] = true;
            if(dfs(p + 2)) return true;
            f.pop_back();
            vis[x] = false;
        }
    }
    return false;
}

int main()
{
    init();
    cin >> s;
    len = s.size() ;
    for(int i = 1; i <= 50; i++)
    {
        if(C[i] == len)
        {
            n = i;
            break;
        }
    }
    dfs(0);
    while(f.size())
    {
        cout << f.front() << " " ;
        f.pop_front();
    }
    return 0;
}
