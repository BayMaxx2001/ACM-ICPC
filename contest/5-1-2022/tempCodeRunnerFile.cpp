#include <bits/stdc++.h>
#define maxn 1000001
using namespace std;

long long a[maxn];
long long b[maxn];
long long n;
long long suma[maxn], sumb[maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0)
        {
            suma[0] += a[i];
            sumb[0] += b[i];
        }
        if (i % 3 == 1)
        {
            suma[1] += a[i];
            sumb[1] += b[i];
        }
        if (i % 3 == 2)
        {
            suma[2] += a[i];
            sumb[2] += b[i];
        }
    }

    long long ans0, ans1, ans2;
    ans0 = suma[1] * sumb[2] + suma[0] * sumb[0] + suma[2] * sumb[1];
    ans1 = suma[1] * sumb[0] + suma[2] * sumb[2] + suma[0] * sumb[1];
    ans2 = suma[1] * sumb[1] + suma[2] * sumb[0] + suma[0] * sumb[2];
    cout << ans0 << " " << ans1 << " " << ans2;
}