#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

struct data
{
    double a;
    double b;
    double ans;
    double g;
    int id;
} a[maxn];
int n;
double A , B;
bool cmp(const data &a, const data &b)
{
    return a.a * b.b > a.b*b.a;
}
bool cmp2(const data &a, const data &b)
{
    return a.id < a.id;
}
void read()
{
    cin >> n >> A >> B ;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i].g >> a[i].a >> a[i].b;
        a[i].id = i;
    }
    sort ( a + 1 , a +1 + n, cmp);
    double suma = 0, sumb = 0;
    for(int i=1;i<=n;i++)
    {
        double res = min((B-sumb)/a[i].b, a[i].g);
        a[i].ans = res;
        suma += a[i].a * res;
        sumb += a[i].b * res;
    }
    if ( suma < A )
    {
        cout << "-1 -1" << endl;
        return;
    }
    sort(a +1 , a + 1 + n, cmp2);
    cout <<fixed << setprecision(8) << suma << " " << sumb << endl ;
    for (int i=1;i<=n;i++)
    {
        cout << a[i].ans << " " ;
    }
}
int main()
{
    read();
    return 0;
}
