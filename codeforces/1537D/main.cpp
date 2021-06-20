#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t ;
    cin >> t;
    while (t--){
        int n ;
        cin >> n ;
        if ( n % 2 ) {
            cout << "Bob" << endl;
            continue;
        }
        int cnt = 0;
        while ( n % 2 == 0 )
        {
            cnt++;
            n/=2;
        }
        if ( n > 1 )
        {
            cout << "Alice" << endl;continue;
        }
        if ( cnt % 2 == 0 )
        {
            cout << "Alice" << endl;continue;
        }
        cout << "Bob" << endl;
    }
    return 0;
}
