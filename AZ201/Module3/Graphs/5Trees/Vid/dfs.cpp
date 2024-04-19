#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n;
vector<vector<int>> g;
int dep[100100];
int par[100100];
int subtreeSz[100100];
int numChild[100100];
bool isLeaf[100100];

void dfs(int node,int parent,int depth){
   dep[node] = depth;
   par[node] = parent;
   numChild[node] = 0;
   subtreeSz[node] = 1;

   for(auto v  : g[node]){
     if(v != parent){
        numChild[node]++;
        dfs(v,node,depth+1);
        subtreeSz[node]+= subtreeSz[v];
     }
   }
   if(!numChild[node]) isLeaf[node] = true;
 
}


void solve(){
  cin>>n;

   for(int i=0;i<n-1;i++){
       int a,b;
       cin>>a>>b;
       g[a].push_back(b);
       g[b].push_back(a);
   }

   dfs(1,0,0);

}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    string temp;getline(cin,temp);

    while(t--) 
        solve();
    
   
}

