#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin>>n;
     
     vector<int> arr(n);

     for(int i=0;i<n;i++){
         cin>>arr[i];
     }

     int q;
     cin>>q;
     while(q--){
         int x;
         cin>>x;


         int left = upper_bound(arr.begin(),arr.end(),x) - arr.begin();
         
     }
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int _t;cin>>_t;while(_t--)
    solve();
}