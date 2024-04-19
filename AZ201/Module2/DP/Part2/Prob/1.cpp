#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int n;
int arr[100100];
int dp[100100];

int rec(int level){
    if(level == n-1){
        return 0;
    }

    if(dp[level] != -1){
        return dp[level];
    }

    int ans =0;

    if(level < n-2){
        ans = min(rec(level+1)+ abs(arr[level] - arr[level+1]), rec(level+2)+ abs(arr[level] - arr[level+2]));
    }else if(level == n-2){
        ans = rec(level+1)+ abs(arr[level] - arr[level+1]);
    }
    

    return  dp[level] = ans;
}

void solve(){
  cin>>n;
  for(int i=0;i<n;i++){
      cin>>arr[i];
  }
  memset(dp,-1,sizeof(dp));
  cout<<rec(0)<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}