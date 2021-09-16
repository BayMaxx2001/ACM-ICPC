#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

void minimize(int &a, int b) {
    if (a > b)
        a = b;
}

int n, m;
vector<int> a[12309];
int start, target;
int c[123][123];
int f[123][123];
int d[12309];

bool bfs(int start, int target) {
    queue<int> qu;

    for (int i = 1; i <= n; i++)
        d[i] = 0;
    d[start] = -1;
    qu.push(start);

    while (qu.size()) {
        int u = qu.front();
        qu.pop();
        if (u == target)
            return true;
        for (int v : a[u])
            if (d[v] == 0 && f[u][v] < c[u][v]) {
                d[v] = u;
                qu.push(v);
            }
    }
    return false;
}

int mincut(bool tracing = false) {
    int r = 0;
    for (int u = 1; u <= n; u++)
        for (int v : a[u])
            if (d[u] && !d[v]) {
                r += c[u][v];
                if (tracing)
                    printf("%d %d\n", u, v);
            }
    return r;
}

void enlarge() {
    int i;
    int delta = 1000111000;
    for (i = target; i != start; i = d[i])
        minimize(delta, c[d[i]][i] - f[d[i]][i]);
    for (i = target; i != start; i = d[i]) {
        f[d[i]][i] += delta;
        f[i][d[i]] -= delta;
    }
}

main() {

        scanf("%d%d", &n, &m);
        if (n == 0)
            return 0;

        for (int i = 1; i <= n; i++)
            a[i].clear();
        for (int p = 1; p <= n; p++)
            for (int q = 1; q <= n; q++)
                c[p][q] = f[p][q] = 0;

        start = 3, target = 5;
        for (int i = 1; i <= m; i++) {
            int p, q;
            scanf("%d%d", &p, &q);
            a[p].push_back(q);
            a[q].push_back(p);
            c[p][q] = c[q][p] = 1;
        }

        while (bfs(start, target))
            enlarge();
        printf("%d", mincut(true));
        printf("\n");
}
//5 8
//1 2
//2 4
//3 4
//1 3
//1 2
//3 4
//3 5
//3 5
