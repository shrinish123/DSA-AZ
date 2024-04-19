#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define ii pair<int,int> 
#define F first
#define S second
#define all(a) a.begin(),a.end()


int n;
vector<vector<int>> g;
int arr[100100];
int dep[100100];
int par[100100][25];
int dp[100100][25];

void dfs(int node , int pp , int d){
    dep[node] = d;
    par[node][0] = pp;
    dp[node][0] = arr[node];

    for(int i=1;i<20;i++){
        par[node][i] = par[par[node][i-1]][i-1];
        dp[node][i] = __gcd(dp[par[node][i-1]][i-1],dp[node][i-1]);
    }

    for(auto v : g[node]){
        if(v != pp){
            dfs(v,node,d+1);
        }
    }
}

int findGCD(int u, int v){
    if(dep[u] < dep[v] ) swap(u,v);

    int dif = dep[u] - dep[v];

    int ans =0;

    for(int i=0;i<20;i++){
        if(dif &(1<<i)){
            ans = __gcd(ans, dp[u][i]);
            u = par[u][i];
        }
    }

    if(u == v) return __gcd(ans, arr[u]);

    for(int i=19;i>=0;i--){
        if(par[u][i] != par[v][i]){
            ans = __gcd(ans , dp[u][i]);
            u=  par[u][i];
            ans = __gcd(ans , dp[v][i]);
            v = par[v][i];
        }
    }

    ans = __gcd(ans,arr[u]); ans = __gcd(ans , arr[v]);
    ans = __gcd(ans,arr[par[u][0]]);
  
   return ans;

}

void solve(){
   cin>>n;
   g.clear();
   g.resize(n+1);

   for(int i=1;i<=n;i++) cin>>arr[i];

   for(int i=0;i<n-1;i++){
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
   }

   dfs(1,0,0);

   int q;
   cin>>q;

   while(q--){
    int u,v; cin>>u>>v;

    cout << findGCD(u,v) << endl;
   }
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
     #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
     #endif
    int _t;cin>>_t;while(_t--)
    solve();
    // cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}