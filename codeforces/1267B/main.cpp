#include<bits/stdc++.h>
using namespace std;
main(){
// freopen("input.txt", "r", stdin);
string s;
cin>>s;

int l=0;
int r=s.length()-1;

while(true){
    if(s[l] != s[r]){
        cout<<"0";
        return 0;
    }
    int tmp = l;
    while(s[tmp]==s[l]) tmp++;
    int lef = tmp - l;

    l=tmp;
    tmp = r;
    while(s[tmp]==s[r]) tmp--;
    int ri = r - tmp;
    // cout<<tmp<<" "<<r<<endl;
    r=tmp;

    if(r<l){
        if(ri<2){
            cout<<"0";
        }else{
            cout<<ri+1;
        }
        return 0;
    }
    if(lef+ri<3){
        cout<<"0";
        return 0;
    }

}
}
