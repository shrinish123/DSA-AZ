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
vector<vector<ii>> g;
int par[100100][25];
int dep[100100];
int pre[100100];

void dfs(int node,int prev, int d, int val){
    dep[node] = d;
    
    pre[node] = pre[prev] + val;

    par[node][0] = prev;

    for(int i=1;i<20;i++){
        par[node][i] = par[par[node][i-1]][i-1];
    }

    for(auto v : g[node]){
        if(v.F != prev){
            dfs(v.F,node,d+1,v.S);
        }
    }
}

int LCA(int u ,int v){
    if(dep[u] < dep[v]) swap(u,v);

    int dif = dep[u] - dep[v];

    for(int i=0;i<20;i++){
        if(dif & (1<<i) ){
            u = par[u][i];
        }
    }

    if(u == v) return u;

    for(int i=19;i>=0;i--){
        if(par[u][i] != par[v][i]){
            u = par[u][i]; 
            v = par[v][i];
        }
    }

    return par[u][0];
}

void solve(){
   cin>>n;
   
   g.clear();
   g.resize(n+1);

   for(int i=0;i<n-1;i++){
    int u,v,w;
    cin>>u>>v>>w;
    g[u].push_back({v,w});
    g[v].push_back({u,w});
   }

   dfs(1,0,0,0);

   int q;
   cin>>q;

   while(q--){
     int u,v;
     cin>>u>>v;

     cout << pre[u] + pre[v] - 2 * pre[LCA(u,v)] << endl;
   }
}


// Tree Prefix Sums 
// On a weighted tree , find for q queries sum of edges on path 
// u to v 


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
     #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("error.txt", "w", stderr);
     freopen("output.txt", "w", stdout);
     #endif
    int _t;cin>>_t;while(_t--)
    solve();
    // cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}