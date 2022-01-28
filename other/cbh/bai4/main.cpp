#include <bits/stdc++.h>
#define maxn 100
#define PB push_back
using namespace std;
struct toado
{
    double x, y;
    int id;
};
vector<toado> a;
vector<int> order;
toado origin;

void read()
{
    for (int i = 1; i <= 5; i++)
    {
        double x, y, z;
        cin >> x >> y >> z;
        if (z == 0)
        {
            a.PB({x, y, i});
        }
        else
        {
            origin = {x, y, i};
        }
    }
}
double kc(toado a, toado b)
{
    return (double)(abs(a.x - b.x) * abs(a.y - b.y));
}

double calc(int i, int j, int k, int z)
{
    double dist1 = kc(origin, a[i]);
    double dist2 = kc(a[i], a[j]);
    double dist3 = kc(a[j], a[k]);
    double dist4 = kc(a[k], a[z]);

    return log(dist1) + log(dist2) + log(dist3) + log(dist4);
}

double calc_trau(int i, int j, int k, int z)
{
    double dist1 = kc(origin, a[i]);
    double dist2 = kc(a[i], a[j]);
    double dist3 = kc(a[j], a[k]);
    double dist4 = kc(a[k], a[z]);
    cout << dist1 * dist2 * dist3 * dist4 << endl;
    return dist1 * dist2 * dist3 * dist4;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("trontim.inp", "r", stdin);
    // freopen("trontim.out", "w", stdout);
    read();
    double ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            for (int k = 0; k < a.size(); k++)
            {
                for (int z = 0; z < a.size(); z++)
                {
                    if (i != j && i != k && i != z && j != k && j != z && k != z)
                    {
                        if (ans < calc_trau(i, j, k, z))
                        {
                            ans = calc_trau(i, j, k, z);
                            order.clear();
                            order.PB(a[i].id);
                            order.PB(a[j].id);
                            order.PB(a[k].id);
                            order.PB(a[z].id);
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < order.size(); i++)
    {
        cout << order[i] << " ";
    }
}
