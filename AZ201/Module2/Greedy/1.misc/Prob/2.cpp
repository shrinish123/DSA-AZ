#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"



void solve(){
   int n,m;
   cin>>n>>m;
   int arr[n];
   for(int i=0;i<n;i++){
       cin>>arr[i];
   }

   if(n>m){
       cout<<0<<endl;
   }else {
       int ans =1;
       for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
               ans = (ans * abs(arr[i] - arr[j]))%m;
           }
       }
       cout<<ans<<endl;
   }
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}