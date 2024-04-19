#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,m;
vector<int> g[100100];
int dp[100100][25];

int gcd(int a,int b){
    if(a==0 || b== 0) return a^b;
    else return gcd(b,a%b);
}

int dfs(int node,int gc,int par){
    
    if(dp[node][gc] != -1){
        return dp[node][gc];
    }
     int ans =0;

    for(int i=1;i<=m;i++){
       int temp =1;
        int child =0;
       for(auto v : g[node]){
           if(v != par){
               child++;
               temp *= dfs(v,gcd(gc,i),node);
           }
       }
       if(child ==0){
           if(gcd(i,gc) == 1)ans++;
       }else {
           ans += temp;
       }
    }

    return dp[node][gc] = ans;
}


void solve(){
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b).
        g[b].push_back(a);
    }
    memset(dp,-1,sizeof(dp));
    cout<<dfs(1,1,0)<<endl;
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}