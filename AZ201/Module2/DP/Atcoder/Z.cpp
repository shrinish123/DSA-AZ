#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int n,c;
int arr[200100];
int dp[200100];

int sq(int x){
    return x*x;
}

int rec(int lvl){
    if(lvl == n-1){
        return 0;
    }

    if(dp[lvl] != -1){
        return dp[lvl];
    }
    int ans = 1e18;
    for(int j = lvl +1; j<n;j++){
      ans = min(ans,sq(arr[j] - arr[lvl]) + c + rec(j));
    }
    return dp[lvl] =ans;
}

void solve(){
   cin>>n>>c;
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