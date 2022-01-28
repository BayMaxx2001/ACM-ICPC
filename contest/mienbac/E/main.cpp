#include <bits/stdc++.h>
#define int long long
#define PB push_back
using namespace std;

long long n;
long long F[20][200][200][11];
long long X[11][200];
long long Y[11][200];
int sum = 0;
int dem = 0;
long long ans = 0;
bool checknt(int n)
{
    if ( n < 2 ) return false;
    if ( n  ==  2 || n == 3 ) return true;
    for(int i=2; i<=sqrt(n); i++)
    {
        if ( n % i == 0 )
        {
            return false;
        }
    }
    return true;
}

void solve( int cs)
{
    for(int i = 0; i <= dem*9; ++i)
    {
        for(int j = 0; j <= dem*9; ++j)
        {
            for(int z = 0; z <= 2; ++z)
            {
                for(int x = 0; x <= 9; ++x)
                {
                    for(int y = 0; y <= 9; ++y)
                    {
                        if((z+x+y*2) % 10 == cs)
                            F[dem][i+x][j+y][(z+x+y*2)/10] += F[dem-1][i][j][z];
                    }
                }
            }
        }
    }
}

main()
{
    cin >> n;
    F[0][0][0][0] = 1;
    while(n)
    {
        dem++;
        int cs = n % 10;
        solve(cs);
        n /= 10;
    }

    for(int x = 2; x <= dem*9; ++x)
        for(int y = 2; y <= dem*9; ++y)
            if(checknt(x) && checknt(y))
                ans += F[dem][x][y][0];


    cout << ans ;
}
