#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n,m;
vector<vector<int>> g;
vector<int> col;
vector<int> parent;
bool iscyc= 0;

void dfs(int node,int par){

    col[node]= 2;
    parent[node]= par;


    for(auto v: g[node]){
        if(v == parent[node]) continue;
        if(col[v]== 1){
            dfs(v,node);
        }
        if(col[v] == 2 ){
            iscyc =1;
        }
    }

    col[node] =3;
}

void solve(){
  cin>>n>>m;

  g.resize(n+1);
  col.assign(n+1,1);
  parent.assign(n+1,0);

  for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      g[a].push_back(b);
      g[b].push_back(a);
  }

  for(int i=1;i<=n;i++){
      if(col[i] == 1){
          dfs(i,0);
      }
  }

  if(iscyc) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
   
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
    solve();
}

// https://www.learning.algozenith.com/problems/Round-Trip-181