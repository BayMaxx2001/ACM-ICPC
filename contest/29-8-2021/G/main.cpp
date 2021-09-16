#include<bits/stdc++.h>
using namespace std;
int arr[1000001];
int vis[1000001];
int good[1000001];
int firs[1000001];
bool check[1000001];
vector<int> snt;
int cal(int n)
{
   int ans=1;
   if(n==0){
      return 0;
   }
   if(n==1){
      return 1;
   }
   for (auto i = snt.begin(); i != snt.end(); ++i){
         // ok=1;
        long long dem = 0;
        while(n % *i == 0){
            ++dem;
            n /= *i;
        }
        if(dem){
            ans*=(dem+1);
        }
        if(*i>n){
         break;
        }
   }
   if(ans==1){
      return 2;
   }

   return ans;
}
main(){
   freopen(".inp", "r", stdin);
   int n;
   int k;
   cin>>n>>k;
   for (int i = 2; i <= n; i++) {
      check[i] = true;
   }
   for (int i = 2; i <= n; i++) {
    if (check[i] == true) {
      for (long long j = 1ll * i * i; j <= n; j += i) {
        check[j] = false;
      }
    }
   }

   for (int i = 2; i <= n; i++) {
    if (check[i] == true) {
      snt.push_back(i);
    }
   }

   for(int i=0;i<n;i++){
      arr[i]= cal(i)+i;
      arr[i] = arr[i]%n;
      vis[i] = 0;
      good[i]=0;
      firs[i]=0;
   }


   for(int i=0;i<n;i++){
      good[arr[i]]=1;
   }


   if(k==1){
      cout<<0;
      return 0;
   }

   // cout<<arr[1];
   // return 0;

   int ans_first = -1;
   long long ans_sum = -1;
   int current_mark = 0;
   for(int i=0;i<n;i++){
      //cout<<"----";
      if(good[i]==1){
         continue;
      }
      if(firs[i]==1){
         continue;
      }
      int count = 1;
      long long current_sum = i;
      int current_node = i;
      int current_first = i;
      current_mark++;
      firs[current_first] = 1;
      // vis[i] = current_mark;
      // cout<<current_first<<" ";
      while(true){
         if(count<k){
            count++;
            if(current_node == 0) {
               break;
            }
            current_node= arr[current_node];
            current_sum+= current_node;
            // cout<<current_node<<" ";
         } else {
            if(current_sum<ans_sum||ans_sum==-1) {
               ans_sum = current_sum;
               ans_first = current_first;
            }
            if(current_node == 0) {
               break;
            }

            current_node = arr[current_node];
            current_sum -= current_first;
            current_sum+= current_node;
            current_first = arr[current_first];
            if(firs[current_first] == 1){
               break;
            }
            firs[current_first]=1;
         }

      }

   }
   if(ans_first==-1){
      cout<<"-1";
      return 0;
   }
   int count = 1;
   cout<<ans_first<<" ";
   while(count<k) {
      ans_first= arr[ans_first];
      cout<<ans_first<<" ";
      count++;
   }

}
