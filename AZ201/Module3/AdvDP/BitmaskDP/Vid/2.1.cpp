#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,m;
vector<vector<int>> g;
int dp[20][1001000];

int rec(int node,int mask){
    if(mask == (1<<n)-1){
        if(node ==n) return 1;
        else return 0;
    }

    if(dp[node][mask] != -1){
        return dp[node][mask];
    }

    int ans =0;

    for(auto v : g[node]){
        if( mask & (1<< (v-1))){
            continue;
        }else{
            ans += rec(v, mask | (1<< (v-1)));
        }
    }

    return dp[node][mask] =ans;
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
     memset(dp, -1,sizeof(dp));
    cout<<rec(0,1)<<endl;

}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}


// No of hamiltonian paths from 1 to N  N => 20