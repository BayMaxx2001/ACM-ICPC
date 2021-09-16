#include<bits/stdc++.h>

using namespace std;
const int N=1e7+6;
int n;
int F[N],G[N],Cnt[N],Ans[N];

/*
F[i] là ước nguyên tố bé nhât của i
G[i]= F[i]^k
Cnt[i]=k
Ans[i] là số ước


i=F[i]^cnt[i] . C
Ước(X)=(cnt[i]+1).Ước(C)
*/

vector<int>snt;
void sangOn()
{
    int d;
    Ans[1]=1;
    for(int i=2;i<=n;++i)
    {
        if(F[i]==0)
        {
            F[i]=i;
            snt.push_back(i);
        }

        d=min(n/i,F[i]);
        for(int j=0;j<snt.size()&&snt[j]<=d;++j)
        {
            F[snt[j]*i]=snt[j];
        }



        d=i/F[i];
        if(F[i]==F[d])
        {
            Cnt[i]=Cnt[d]+1;
            G[i]=G[d]*F[i];
        }
        else
        {
            Cnt[i]=1;
            G[i]=F[i];
        }
        d=i/G[i];
        Ans[i]=Ans[d]*(Cnt[i]+1);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    sangOn();
    /*int check=0;
    for(int i=1;i<=n;++i)
    {
        check=0;
        for(int j=1;j<sqrt(i);++j)
        {
            if(i%j==0)check+=2;
        }
        int d=sqrt(i);
        if(d*d==i)
            check++;
        if(check!=Ans[i])
        {
            cout<<"sai";
            return 0;
        }
    }*/
    return 0;
}
