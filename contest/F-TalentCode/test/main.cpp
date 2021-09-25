#include <bits/stdc++.h>
#define maxn 1000000
#define ll long long

using namespace std;

string s1, s2;
char save[30];
int n, m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s1;
    cin >> s2;
    for (int i = 0; i < 26; i++)
    {
        save[i] = 'A' + i;
    }
    m = s1.size();
    n = s2.size();
    for (int j = 0; j < n; j++)
    {
        if (s2[j] < '0' || s2[j] > '9') continue;
        s2[j] = save[('J' - 'A' + s2[j] - '0') % 26];
    }
    int j = -1;
    string x = s2;
    while ( s2.size() < s1.size() )
        s2 = s2 + x;
    string ans = "";
    for (int i = 0; i < m; i++)
    {
        j++;
        int x = ((s1[i] - 'A') + (s2[j] - 'A')) % 26;
        ans = ans + save[x];
    }
    cout << ans;
    return 0;
}
