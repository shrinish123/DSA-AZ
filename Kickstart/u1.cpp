#include<bits/stdc++.h>
using namespace std;

#define int long long
int dp[1000][1000];
int n;

int rec(int lil,int noted){
    if(lil == n){
        return 0;
    }

    if(dp[lil][noted] != -1){
        return dp[lil][noted];
    }

    int ans =1e9;

      if(lil !=0){
          ans = min(ans, 4 + rec(lil,lil));
      }
      

    if(lil + 1 <= n){
        ans = min(ans,1 + rec(lil+1,noted));
    }
    if(lil+ noted <= n){
        ans = min(ans, 2 + rec(lil+ noted,lil));
    }
    
    return dp[lil][noted] = ans;
}

void solve(){
    cin>>n;
    memset(dp,-1,sizeof(dp));

    cout<<rec(0,0)<<endl;
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}