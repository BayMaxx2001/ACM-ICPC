#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long red, blue, a, b;

void solve()
{
    if (a == b) {
        cout << min(red, blue) / a << endl;
        return;
    }
    long l = 0 , r = 1e9+2;
    while ( r - l > 1 ){
        ll mid = (l + r)/2;
        ll right = floorl((red - mid * b) * 1.0l / (a - b));
        ll left = ceill((blue - mid * a) * 1.0l / (b - a));
        if (max(left, 0ll) <= min(right, mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;

}
int main()
{
    int te=1;
    cin >> te ;
    while(te--)
    {
        cin >> red >> blue >> a >> b;
        if (a<b) swap(a,b);
        solve();
    }

    return 0;
}
