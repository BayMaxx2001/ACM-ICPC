#include <bits/stdc++.h>
#define maxn 500005
using namespace std;
string s;
int k;
int save[maxn];
void read()
{
    cin >> s;
    cin >> k;
    for(int i=1;i<=k;i++)
    {
        int x, l , r;
        cin >> x >> l >> r;
        l --;
        r --;
        save[l]+=x;
        save[r+1]-=x;
    }
    for(int i=0;i<s.size();i++)
    {
        save[i]+=save[i-1];
    }
    for(int i=0;i<s.size();i++)
    {
        int inc = save[i]%27;
        //cout << inc << endl;
        cout << char(((int)s[i]-'A'+ save[i])%26+'A') ;
    }
}
int main()
{
    read();
    return 0;
}
