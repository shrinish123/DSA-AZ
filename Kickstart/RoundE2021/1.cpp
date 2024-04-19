#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'

void solve(int t){
   int n,k,s;
   cin>>n>>k>>s;
   int prev=  k-1;

   int opt1 = (k-s) + (n-s +1);
   int opt2 = (n+1);
   int ans =0;

   if(opt1 > opt2){
      ans = opt2;
   }else ans = opt1;
  
   cout<<"Case #"<<t<<": "<< ans + prev<<endl;
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