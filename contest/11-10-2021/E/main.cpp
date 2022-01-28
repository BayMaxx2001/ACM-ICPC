#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    cin >> n;
    if ( n <= 56 )
    {
        int h = 1;
        int w = 1;
        string s = "0abcdefgh";
        cout<<"a1"<<" ";
        int du = 0;
        while(n>2)
        {
            n--;
            if(h%2==0)
            {
                if(w>1)
                {
                    w--;
                }
                else
                {
                    h++;
                }
            }
            else
            {
                if(w<8)
                {
                    w++;
                }
                else
                {
                    h++;
                }
            }
            cout<<s[w]<<h<<" ";

        }
        if (w==8)
        {
            h++;
            cout<<s[w]<<h<<" ";
            cout<<"h8";
            return 0;
        }
        else
        {
            cout<<s[w]<<8<<" ";
            cout<<"h8";
            return 0;
        }
    }
    if ( n > 56 )
    {
        for(int i=1; i<=6; i++)
        {
            if ( i % 2 == 0)
            {
                for(int j=8; j>=1; j--)
                {
                    cout << (char)('a' + j - 1) << i << " ";
                }
            }
            else
            {
                for(int j=1; j<=8; j++)
                {
                    cout << (char)('a' + j - 1) << i << " ";
                }
            }
        }
        cout << "a7 a8 b8 b7 c7 c8 d8 d7 " ;
        switch(n)
        {
        case 57:
            cout << "h7 h8" ;
            break;
        case 58:
            cout << "e7 h7 h8";
            break;
        case 59:
            cout << "e7 f7 h7 h8";
            break;
        case 60:
            cout << "e7 f7 g7 h7 h8";
            break;
        case 61:
            cout << "e7 e8 f8 f7 h7 h8";
            break;
        case 62:
            cout << "e7 e8 f8 f7 g7 h7 h8";
            break;
        case 63:
            cout << "e7 e8 f8 f7 h7 g7 g8 h8";
            break;
        }
    }
    return 0;
}
