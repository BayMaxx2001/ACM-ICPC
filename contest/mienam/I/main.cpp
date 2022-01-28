#include<bits/stdc++.h>
#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define maxn 1000006
using namespace std;
int n, a[maxn], t1[maxn], t2[maxn];
long long l[maxn], r[maxn];
void up1(int x)
{
    for (;x;x-=x&-x) t1[x]++;
}
void up2(int x)
{
    for (;x<maxn; x+=x&-x) t2[x]++;
}
int get1(int x)
{
    int ans = 0;
    for (;x<maxn; x+=x&-x) ans += t1[x];
    return ans;
}
int get2(int x)
{
    int ans = 0;
    for (;x;x-=x&-x) ans += t2[x];
    return ans;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    f1 (i, n) cin >> a[i];
    f1 (i, n)
    {
        l[a[i]] = get1(a[i]);
        up1(a[i]);
    }
    for (int i=n; i; i--)
    {
        r[a[i]] = get2(a[i]);
        up2(a[i]);
    }
    //f1 (i, n) cout << l[i] << ' '; el;
    //f1 (i, n) cout << r[i] << ' ';
    f1 (i, n) r[i] += r[i-1];
    for (int i=n; i; i--) l[i]+=l[i+1];
    //f1 (i, n) cout << l[i] << ' '; el;
    //f1 (i, n) cout << r[i] << ' '; el;
    long long ans = 1e15;
    f1 (i, n) ans = min(ans, r[i-1] + l[i+1]);
    cout << ans;
}
