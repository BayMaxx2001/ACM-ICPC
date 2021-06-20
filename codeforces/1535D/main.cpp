#include <bits/stdc++.h>
#define maxn 2000000
using namespace std;
int n , a[maxn] ;
string s ;
int x;
int F[maxn];
void dfs(int i)
{
    if ( s[i] == '1')
        F[i] = F[i*2];
    if ( s[i] == '0')
        F[i] = F[i*2+1];
    if ( s[i] == '?')
        F[i] = F[i*2]+F[i*2+1];
}

int main()
{
    cin >> n ;
    cin >> s;
    reverse(s.begin(),s.end());
    s= " " + s ;
    n = (1<<n);
    for ( int i=n;i<=2*n-1;i++) F[i]=1;
    for( int i=n-1;i>=1;i--)
        dfs(i);
//    for ( int i=1;i<=n;i++)
//        cout << i<< " " << F[i]<< endl;
    int query;
    cin >> query;
    for( int i=1;i<=query;i++)
    {
        int p; char c;
        cin >> p >> c;
        p = n-p;
        s[p] = c;
        //cout << s << " -- "<< endl;
        while(p>0)
        {
            dfs(p);
            p /= 2;
        }
//        for ( int i=1;i<=n;i++)
//            cout << i<< " " << F[i]<< endl;
        cout << F[1] << '\n';
    }
    return 0;
}
