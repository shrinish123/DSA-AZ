#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'

void solve(int t){
   
   int n,m;
   cin>>n>>m;
   int sum =0;
   for(int i=0;i<n;i++){
       int x;
       cin>>x;
       sum+=x;
   }  
   cout<<"Case #"<<t<<": "<<sum%m<<endl;
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