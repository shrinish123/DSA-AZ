#include<bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second

int n,m;
vector<vector<pair<int,int>>> g;
int dp[25][1001000];


int rec(int node,int mask){

    if(mask == (1<<n) -1){
        if(node == n-1)return 0;
        else return 1e18;
    }

    if(dp[node][mask] != -1){
        return dp[node][mask];
    }

    int ans =1e18;
    
    for(auto v : g[node]){
          
         if(mask & 1<< (v.F-1) ){
             continue;
         }else{

             ans = min(ans, rec(v.F, mask | (1 << (v.F-1))) + v.S);
         }
    }

    return dp[node][mask] = ans;


}


void solve(){
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

     memset(dp,-1,sizeof(dp));
    
    cout<<rec(0,1)<<endl;
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}


/// Shortest hamiltonian on wirghted graph