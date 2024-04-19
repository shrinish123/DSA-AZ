#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n,m;
int dp[60][100100];
int happy[60][20];

int rec(int lvl,int mask){
    if(lvl == m){
        return 0;
    }

    if(dp[lvl][mask] != -1){
        return dp[lvl][mask];
    }

    int ans = dp(lvl+1,mask);

    for(int i=0;i<n;i++){
        if(mask & (1<<i) == 0 ){
           ans = max(ans, dp(lvl+1, mask | (1<<i)));
        }
    }

    return dp[lvl][mask] = ans;
}

void solve(){
    cin>>n>>m;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>happy[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;

}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int _t;cin>>_t;while(_t--)
    solve();
}