#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n;
vector<vector<int>> g;
int dep[100100];


void dfs(int node,int parent,int depth){
   dep[node] = depth;
   

   for(auto v  : g[node]){
     if(v != parent){
        dfs(v,node,depth+1);
     
     }
   }
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
   int dia1=0;
   int y;
   for(int i=2;i<=n;i++){
     if(dia1 > dep[i]){
      y = i;
     }
   }

   dfs(y,0,0);
   
   int ans = 0;

   for(int i=1;i<=n;i++){
       if(ans>dep[i])
       ans = dep[i];
   }

   cout<<ans<<endl;

}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    string temp;getline(cin,temp);

    while(t--) 
        solve();
    
   
}


// Also remember (2E - dia) gives path dis to travel all nodes in min time 