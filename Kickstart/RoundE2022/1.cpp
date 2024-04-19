#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'

void solve(int t){

   int n;
   cin>>n;
   int ans=0;

   if(n%5){
       ans = n/5 + 1;
   }else {
       ans = n/5;
   }
  
   cout<<"Case #"<<t<<": "<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
      solve(i);
    }
}