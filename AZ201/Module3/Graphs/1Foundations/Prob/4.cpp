#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

vector<vector<int>> g;
vector<int> vis;

vector<int> siz;
vector<int> compn;

int n,m,q;
int nodeVis =0;
int compnum = 1;
vector<int> curcom;

void dfs(int node){
    vis[node] = 1;
    nodeVis++;
    curcom.push_back(node);

    for(auto v :g[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
}


void solve(){
  cin>>n>>m>>q;
  g.clear();
  g.resize(n+1);
  vis.assign(n+1,0);
  siz.resize(n+1);
  compn.resize(n+1);


  for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      g[a].push_back(b);
      g[b].push_back(a);
  }
  

  for(int i=1;i<=n;i++){
      if(!vis[i]){
          nodeVis=0;
          dfs(i);
          for(auto v : curcom){
              siz[v] = nodeVis;
              compn[v] = compnum;
          }
          compnum++;
          curcom.clear();
      }
  }

   

  while(q--){
      int t;
      cin>>t;
      if(t==1){
          int x;
          cin>>x;
          cout<<siz[x]<<endl;

      }else {
          int x,y;
          cin>>x>>y;
          if(compn[x] == compn[y])  cout<<"YES"<<endl;
          else cout<<"NO"<<endl;
      }
  }


}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
    solve();
}

// https://www.learning.algozenith.com/problems/Easy-Graph-Queries-374