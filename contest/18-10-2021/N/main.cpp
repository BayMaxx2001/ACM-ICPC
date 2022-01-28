#include <bits/stdc++.h>
#define MOD 100000000000000007
using namespace std;
#define int long long
int a[8];
int solve( int day , int k )
{
    int dem = 0, last = 0;
    for(int i=1;i<=7;i++)
    {
        if ( a[i] == 1 )
        {
            dem++;
        }
    }

    for(int i=day;i<=7;i++)
    {
        if ( a[i] == 1 )
        {
            last = i-day+1;
        }
    }
    int tru = 0;
    for(int i=1;i<day;i++)
    {
        if( a[i] == 1 )
        {
            tru ++;
        }
    }
    int rem = k % dem ;
    int cnt = 0;
    int save = 0;
    int ddtru = 0, vt = 0 ;
    for(int i=day+1;i<=7;i++)
    {
        if( a[i] == 1 )
        {
            ddtru ++;
            vt = i-day+1;
            if ( ddtru == tru  ) break;
        }
    }
    if ( ddtru != tru )
    {
        for(int i=1;i<day;i++)
        {
            if ( a[i]==1)
            {
                ddtru ++ ;
                vt = i + 7 - day;
                if ( ddtru == tru ) break;
            }
        }
    }


    for(int i=day;i<=7;i++)
    {
        if( a[i] == 1 )
        {
            cnt ++;
            save = i-day+1;
            if ( cnt == rem  ) break;
        }
    }
    if ( cnt != rem )
    {
        for(int i=1;i<day;i++)
        {
            if ( a[i]==1)
            {
                cnt ++ ;
                save = i + 7 - day;
                if ( cnt == rem ) break;
            }
        }
    }

    int chuky = k/dem;
    if ( k % dem != 0)
    {
        cout << tru << " " ;
        return chuky*7 + save - tru + vt;
    }

    if ( k % dem == 0 )
    {
        return (chuky-1)*7 + last - tru ;
    }

}
void read()
{
    int k;
    cin >> k;
    for(int i=1;i<=7;i++)
    {
        cin >> a[i];
    }

    int ans = MOD;
    for(int day = 1; day <=7 ;day++)
    {
        if ( a[day] == 1 )
        {
            ans = min(ans,solve(day,k));
            //cout << day << " " << solve(day,k) <<endl ;
        }
    }
    cout << ans << endl ;

}
main()
{
    int te;
    cin >> te;
    while ( te -- )
    {
        read();
    }
    return 0;

}
