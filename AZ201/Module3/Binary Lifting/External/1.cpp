#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define ii pair<int,int> 
#define F first
#define S second
#define all(a) a.begin(),a.end()

int n,m;
vector<vector<int>> g;
int par[200200][25];
int dep[200200];

void dfs(int node, int prev , int d){
    dep[node] = d;  
    
    par[node][0] = prev;

    for(int i=1;i<20;i++){
        par[node][i] = par[par[node][i-1]][i-1];
    }

    for(auto v : g[node]){
        if(v != prev){
            dfs(v,node,d+1);
        }
    }
}

bool LCA(int u, int v){

    int dif = dep[u] - dep[v];
    
    for(int i=0;i<20;i++){
        if(dif & (1<<i)){
            u = par[u][i];
        }
    }

    if( u == v) return true;
     
    u = par[u][0] ; v = par[v][0];

    return u == v; 
}

void solve(){
  cin>>n>>m;
  g.clear(); g.resize(n+1);

  for(int i=0;i<n-1;i++){
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1,0,0);

  while(m--){
    int k; cin>>k;
    vector<ii> deps;

    for(int i=0;i<k;i++){
        int x; cin>>x;
        deps.push_back({dep[x],x});
    }
    sort(all(deps));
    bool ok = 1;
    for(int i=0;i<k-1;i++){
      ok = ok && LCA(deps[i+1].S , deps[i].S);
    }

    cout << ( ok ? "YES" : "NO" ) << endl;
  }

}

//  https://codeforces.com/contest/1328/problem/E



signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
     #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("error.txt", "w", stderr);
     freopen("output.txt", "w", stdout);
     #endif
    // int _t;cin>>_t;while(_t--)
    solve();
    // cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}