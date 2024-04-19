#include<bits/stdc++.h>
using namespace std;


#define int long long 
#define endl '\n'

void solve(){
  
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
      cin>>arr[i];
  }

  int pre[n],suff[n];

  pre[0]  = arr[0];
  suff[n-1] = arr[n-1];

  for(int i=1;i<n;i++){
      pre[i] =  max(pre[i-1],arr[i]);
  }

  for(int i=n-2;i>=0;i--){
      suff[i] = max(suff[i+1],arr[i]);
  }
  int ans =0;
  for(int i=0;i<n;i++){
   ans+=(min(pre[i],suff[i]) - arr[i]) ;
  }
  cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _;cin>>_;
    string temp;
    getline(cin,temp);
    while(_--)
    solve();

}