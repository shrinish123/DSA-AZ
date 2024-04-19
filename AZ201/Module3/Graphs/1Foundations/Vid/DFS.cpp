#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

vector<vector<int>> g;
int n,m;
vector<int> vis;
int nodevisited=0;

void dfs(int node){
    vis[node] = 1;
    nodevisited++;

    for(auto v : g[node]){
        if(!vis[v]){
            dfs(v);
        }
    }

}


void solve(){

    cin>>n>>m;
    
    g.clear();
    g.resize(n+1);
    vis.assign(n+1,0);
  
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> comp;

    for(int node =1;node<=n;node++){
        if(!vis[node]){
            nodevisited=0;
            dfs(node);
            comp.push_back(nodevisited);
        }
    }
  
   int sum= 0;
   for(auto it :comp){
        sum+= it;
    }


   int ans =0;
    for(auto it: comp){
        ans += it * (sum -it);
       }

     cout<<ans/2<<endl;
    
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
    solve();
}