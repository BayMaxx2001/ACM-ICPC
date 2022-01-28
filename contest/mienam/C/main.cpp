#include <bits/stdc++.h>

using namespace std;
string s;
int sl ;
void solve(char ans)
{
    char ans1='z';
    for(int i=0;i<s.size();i++)
    {
        if(ans == s[i])
        {
            if ( i==0)
                ans1 = min(ans1,s[i+1]);
            else if ( i == s.size()-1 )
                ans1 = min(ans1, s[i-1]);
            else ans1 = min(ans1, min(s[i-1], s[i+1]));
        }
    }
    int oke = 1;
    for(int i=1;i<=sl;i++)
    {
        if(oke == 1)
            cout<< ans;
        else
            cout << ans1;
        oke = 1 - oke;
    }
}
int main()
{
    cin >> s;
    cin >> sl ;
    char ans = 'z';

    for(int i=0;i<s.size();i++)
    {
        ans = min(ans,s[i]);
    }
    solve(ans);
    return 0;
}
