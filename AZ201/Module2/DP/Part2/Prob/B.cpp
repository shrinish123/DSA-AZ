#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int n,k;
int arr[100001];
int dp[100001];

int rec(int lvl){
    if(lvl == n-1){
        return 0;
    }

    if(dp[lvl] != -1){
        return dp[lvl];
    }
   
    // transitins 
    int ans = rec(lvl+1) + abs(arr[lvl] - arr[lvl + 1]);
    for(int i=1;i<=k;i++){
        if(lvl + i >n-1){

        }else {
        
            ans = min(ans, rec(lvl+i) + abs(arr[lvl] - arr[lvl + i]));
        }
    }

    //save 
   
    return dp[lvl] = ans;
}

void solve(){
  cin>>n>>k;
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