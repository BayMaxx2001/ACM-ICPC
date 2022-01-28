#include <bits/stdc++.h>

using namespace std;
int n;
int tu1, mau1, tu2, mau2;
int main()
{
    cin >> n;
    if ( n <= 3 )
    {
        cout <<"NO";
        return 0;
    }
    int ori = n;
    for(int i=2;i<sqrt(n);i++)
    {
        if(n%i ==0)
        {
            int res = 1;
            while(n%i == 0)
            {
                n /= i;
                res = res * i;
                if ( n == 1)
                {
                    cout << "NO" ;
                    return 0;
                }
            }
            if ( res != 1 )
            {
                mau1 = res;
                mau2 = ori/res;
                break;
            }
        }
    }
    if ( mau1 == 0 && mau2 == 0 )
    {
        cout << "NO" ;
        return 0;
    }
    int x = 0;
    while(true)
    {
        int k = ori - 1 - x * mau2;
        if ( k % mau1 == 0 )
        {
            cout <<"YES" << endl;
            cout << "2" << endl;
            cout << x << " " << mau1 << endl;
            cout << k/mau1 << " " << mau2 << endl;
            return 0;
        }
        x++;
    }
    return 0;
}
