#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n,m;
vector<vector<int>> g;
vector<int> indeg;
vector<int> topo;



void kahn(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indeg[i]== 0){
            q.push(i);
        }
    }
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            topo.push_back(cur);
           
            for(auto v: g[cur]){
               indeg[v]--;
               if(indeg[v] == 0){
                   q.push(v);
              
               }
             
            }
        }
    
}

void solve(){
  cin>>n>>m;
 g.resize(n+1);
 indeg.assign(n+1,0);

 for(int i=0;i<m;i++){
     int a,b;
     cin>>a>>b;
     g[a].push_back(b);
     indeg[b]++;
 }
  
  kahn();
  
  for(auto v :topo){
      cout<<v<<" ";
  }
  cout<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
    solve();
}