#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,m;
vector<vector<int>> g;
vector<vector<int>> trans;
vector<int> topo;
vector<vector<int>> ans;
vector<int> sol;

vector<int> vis;

void dfs2(int node){
    sol.push_back(node);
    vis[node] =1;

    for(auto v : trans[node]){
        if(!vis[v]){
            dfs2(v);
        }
    }
}

void dfs(int node){
  
  vis[node] =1;

  for(auto v : g[node]){
      if(!vis[v]){
          dfs(v);
      }
  }
  
  topo.push_back(node);
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);

    for(int i=0;i<m;i++){
        int a,b;
        cin>.a>>b;
        g[a].push_back(b);
    }
  

    dfs(1);
    
    reverse(topo.begin(),topo.end());

    //transpose


   for(auto v : g){
       for(auto x : v){
           trans[x].push_back(v);
       }
   }

   // dfs in topo sort

   vis.assign(n+1,0);

   

   for(auto v : topo){
      if(!vis[v]){
          dfs2(v);
          ans.push_back(sol);
          sol.clear();
      }
   }

   for(auto sol : ans){
       for(auto v : sol){
           cout<< v <<" ";
       }
       cout<<endl;
   }


}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}