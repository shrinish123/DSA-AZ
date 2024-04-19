#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,x;
int arr[200100];
int dp[200100];

int rec(int level){
    if (level == n ){
        return 0;
    }

    if(dp[level] != -1){
        return dp[level];
    }

    int ans = 1e18;

    ans = arr[level] + rec(level+1);

    if( level == 0){
      ans = min( ans , x + arr[n-1] + rec(level+1));
    }else {
    ans = min(ans, x + arr[level-1] + rec(level+1));
    }

    return dp[level] =ans;
    
}

void solve(){
    cin>>n>>x;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    memset(dp,-1,sizeof(dp));

    cout<<rec(0)<<endl;
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int _t;cin>>_t;while(_t--)
    solve();
}