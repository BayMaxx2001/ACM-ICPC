#include <bits/stdc++.h>
#define PB push_back
using namespace std;
void solve()
{
    int ans = 0;
    string s;
    cin >> s;

    int i = 0;
    while ( i < s.size())
    {
        if ( s[i] == '0')
        {
            i++;
            continue;
        }
        if ( i > 0 && s[i-1] == '0')
        {
            i++;
            continue;
        }
        if ( i < s.size()-1 && s[i+1] =='0')
        {
            s[i+1] = '1';
            i+=2;
            continue;
        }
        ans ++;
        i++;
    }
    cout << ans << endl;
}
int main()
{
    int te;
    cin >> te;
    while (te--){
        solve();
    }
    return 0;
}
