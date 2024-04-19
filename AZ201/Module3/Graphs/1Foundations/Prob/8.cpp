#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve(){
  int n;
  cin>>n;
  vector<int> arr(n+1,0);

  for(int i=1;i<=n-1;i++){
     int a,b;
     cin>>a>>b;
     arr[a]++;
     arr[b]++;
  }
  int ans =0;
  for(int i=1;i<=n;i++){
     ans = max(ans,arr[i]);
  }
  cout<<ans+1<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
    solve();
}

// https://www.learning.algozenith.com/problems/Colour-Tree-390