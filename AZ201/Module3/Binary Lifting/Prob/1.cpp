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
int par[100100][25];
int dep[100100];

void dfs(int node, int prev, int d){
   dep[node] = d;
   par[node][0] = prev;

   for(int i=1;i<20;i++){
    par[node][i] = par[par[node][i-1]][i-1];
   }

   for(auto v: g[node]){
    if(v != prev){
        dfs(v, node,d+1);
    }
   }
}

int LCA(int u, int v){

    if(dep[u] < dep[v]) swap(u,v);

    int dif = dep[u] - dep[v];
    for(int i=0;i<20;i++){
        if(dif & (1<<i)){
            u = par[u][i];
        }
    }

    if( u == v) return u;

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
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1,0,0);

  int q;
  cin>>q;

  while(q--){
    int x,y,z;
    cin>>x>>y>>z;
    
    int l1 = LCA(x,y); 
    int l2 = LCA(x,z); 
    int l3 = LCA(y,z); 

    if(dep[l1] >= dep[l2] && dep[l1] >= dep[l3]){
        cout << l1 << endl;
    }
    else if(dep[l2] >= dep[l1] && dep[l2] >= dep[l3]){
        cout << l2 << endl;
    }
    else if(dep[l3] >= dep[l1] && dep[l3] >= dep[l2]){
        cout << l3 << endl;
    }
  }

} 

// Tree with N nodes and q queries
// for every query x,y,z find the LCA of x,y if Z is the root 



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