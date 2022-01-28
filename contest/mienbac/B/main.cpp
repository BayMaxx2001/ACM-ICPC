#include <bits/stdc++.h>
#define foru(i,a,b) for(int i=(a);i<=b;++i)
#define ford(i,a,b) for(int i=(a);i>=b;--i)
#define all(v)      v.begin(),v.end()
#define ii          pair<int, int>
#define eb          emplace_back
#define bit(i)      (i & (-i))
#define int         long long
#define mp          make_pair
#define pb          push_back
#define maxn        100005
#define sd          second
#define ft          first
#define endl        "\n";
using namespace std;
string yno[] = {"NO\n", "YES\n"};
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, dp[20][9*16][9*16][5];
int p[9*16];

void read() {
    cin >> n;
}

void snt() {
    for(int i = 2; i <= 9*16; ++i)
        p[i] = true;
    for(int i = 2; i <= 9*16; ++i)
        if(p[i])
            for(int j = i+i; j <= 9*16; j += i)
                p[j] = false;
}

void solve() {
    snt();
    int sum = 0;
    dp[0][0][0][0] = 1;
    int cnt = 0;
    while(n) {
        cnt++;
        int k = n % 10;
        for(int i = 0; i <= sum; ++i)
            for(int j = 0; j <= sum; ++j)
                for(int tight = 0; tight <= 2; ++tight)
                    for(int x = 0; x <= 9; ++x)
                        for(int y = 0; y <= 9; ++y)
                            if((tight+x+y*2) % 10 == k)
                                dp[cnt][i+x][j+y][(tight+x+y*2)/10] += dp[cnt-1][i][j][tight];
        sum += 9;
        n /= 10;
    }
    int res = 0;
    for(int x = 2; x <= sum; ++x)
        for(int y = 2; y <= sum; ++y)
            if(p[x] && p[y])
                res += dp[cnt][x][y][0];
    cout << res;
}

#undef int
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test = 1;
    int tc = 0;
    // cin >> test;
    while (test--) {
        // cout << "TestCase "<<++tc<<" :";
        read();
        solve();
    }

    return 0;
}
