#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n;
vector<vector<int>> g;

vector<int> dep;
vector<int> par;
vector<int> subtree;

void dfs(int node,int parent,int depth){
    par[node] = parent;
    dep[node] = depth;
    subtree[node] =1;
    for(auto v : g[node]){
        if(v != parent){
            dfs(v,node,depth+1);
            subtree[node] += subtree[v];
        }
    } 
}

void solve(){
  cin>>n;
  g.resize(n+1);
  dep.resize(n+1);
  par.resize(n+1);
  subtree.resize(n+1);

  for(int i=0;i<n-1;i++){
      int a,b;
      cin>>a>>b;
      g[a].push_back(b);
      g[b].push_back(a);
  }

  dfs(1,0,0);
  int ans =0;
  for(int i=1;i<=n;i++){
     ans += subtree[i] * (n - subtree[i]);
  }

  cout<<ans<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
        solve();
    
   
}