#include<bits/stdc++.h>
#define maxn 100010
long long arr[maxn];
long long miri[maxn];
using namespace std;
main()
{
//    freopen("input.txt", "r", stdin);
    long long n, s;
    cin>>n>>s;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    if(n==1)
    {
        cout<<arr[1];
        return 0;
    }
    miri[n] = arr[n];

    for(int i=n-1; i>=0; i--)
    {
        miri[i] = min(miri[i+1],arr[i]);
    }


    for(int i=0;i<n;i++)
    {
        if ( )
    }
    cout<<ans;




}
