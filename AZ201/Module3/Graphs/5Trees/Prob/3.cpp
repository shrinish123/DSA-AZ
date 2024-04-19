#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n;
vector<vector<int>> g;
vector<int> dep;
vector<int> par;

void dfs(int node,int parent,int depth){
    par[node] = parent;
    dep[node] = depth;

    for(auto v : g[node]){
        if(v != parent){
            dfs(v,node,depth+1);
        }
    }
}

void solve(){
    cin>>n;
   g.resize(n+1);
  dep.assign(n+1,1e9);
  par.resize(n+1);

   for(int i=0;i<n-1;i++){
       int a,b;
       cin>>a>>b;
       g[a].push_back(b);
       g[b].push_back(a);
   }

   dfs(1,0,0);
   int y=1;int maxval = 0;

   for(int i=1;i<=n;i++){
       if(dep[i] > maxval){
           y =i;
           maxval = dep[i];
       }
   }
    
    dfs(y,0,0); 
   int z=1;
   maxval =0;

   for(int i=1;i<=n ;i++){
       if(dep[i] > maxval){
           z =i;
           maxval = dep[i];
       }
   }

   if(maxval%2 == 0){
       int temp = z;
       int j = maxval/2;
       while(j--){
           temp = par[temp];
       }

       cout<<temp<<endl;
   }else {
       cout<<-1<<endl;
   }

}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
        solve();
    
   
}