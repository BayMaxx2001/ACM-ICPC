#include <bits/stdc++.h>
#define maxn 500005
#define PB push_back
#define int long long
using namespace std;
string s;
long long save[maxn];
vector<long long> indexxx[maxn];
long long ans = 0;
void calc(long long ch)
{
    if ( indexxx[ch].size() <= 2 ) return;
    for(int i=1;i<indexxx[ch].size()-1;i++)
    {
        int vt = indexxx[ch][i];
        long long  l = 1ll * vt - (indexxx[ch][i-1]+1ll);
        long long  r = 1ll * indexxx[ch][i+1] - vt-1ll;
        ans = ans + 1ll*(r+1ll) * (l+1ll) ;
//        cout << char(ch) << " ";
//        cout << l << "--"<<r << " -- " <<r * l << " " ;
    }
}

void read()
{
    cin >> s;
    long long le = s.size();
    ans = 0;
    for(long long i='a';i<='z';i++)
    {
        save[i] = 0;
        indexxx[i].clear();
    }
    for(int i=0;i<s.size();i++)
    {
        if ( indexxx[s[i]].size() == 0 )
        {
            //ans ++ ;
            indexxx[(s[i])].PB(-1);
        }
        indexxx[(s[i])].PB(i);
    }

    for(int i='a';i<='z';i++)
    {
        indexxx[i].PB(le);
        calc(i);
    }
//    cout << endl;
//    for(long long i='a';i<='z';i++)
//    {
//        cout << char(i) << " " ;
//        for(long long j=0;j<indexxx[i].size();j++)
//        {
//            cout << indexxx[i][j] << " ";
//        }
//        cout << endl;
//    }
    cout << ans << endl ;
}
main()
{
    long long te;
    cin >> te;
    while ( te--)
    {
        read();
    }

}
