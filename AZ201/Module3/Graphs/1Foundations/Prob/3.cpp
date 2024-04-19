#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n,m;
vector<vector<int>> g;
vector<int> col;

bool isbip =1;

void dfs(int node,int color){
    col[node] =color;

    for(auto v : g[node]){
       if(col[v] == 1){
           if(color ==2 ){
               dfs(v,3);
           }else {
                dfs(v,2);
           }
           
       }else if(col[v] == color){
           isbip=0;
       }
    }
}

void solve(){
  cin>>n>>m;

  g.resize(n+1);
  col.assign(n+1,1);

  for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;

      g[a].push_back(b);
      g[b].push_back(a);
  }
  


  for(int i=1;i<=n;i++){
      if(col[i] == 1){
          dfs(i,2);
      }
  }
   
   if(isbip) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;

}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
    solve();
}

// https://www.learning.algozenith.com/problems/Creating-Teams-180

