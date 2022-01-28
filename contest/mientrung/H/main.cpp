#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

struct da{
    double x;
    double y;
}a[5];
double R, P;
int main()
{
    for(int i=1;i<=3;i++)
    {
        cin >> a[i].x >> a[i].y;
    }

    cin >> R >> P;
    double S = abs(
                   (a[2].x - a[1].x)*(a[3].y-a[1].y)-
                   (a[3].x - a[1].x)*(a[2].y-a[1].y)
                   )*0.5;

    double ab = sqrt(
                     (a[1].x-a[2].x)*(a[1].x-a[2].x)+
                     (a[1].y-a[2].y)*(a[1].y-a[2].y)
                     );
    double kc = S*2.0/ab;
    double co = kc/R;
    double goc = acos(co)/PI*180;
    goc = goc * 2.0;
    double Stron = PI * R * R;
    double s1 = goc/360 * Stron;
    double s2 = s1 - S;
    double s3 = P/100 * Stron;
    double s4 = abs(s2-s3);
    double s5 = s4/Stron * 100;
    if ( s5 <= 5 )
    {
        cout <<"YES";
    }
    else
        cout <<"NO";
    return 0;
}
