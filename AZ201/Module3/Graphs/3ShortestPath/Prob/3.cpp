#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define ii pair<int,int>
#define F first
#define S second

int n,m;
vector<vector<ii>> g;
vector<int> dist;
vector<bool> marked;

void dij(int node){
    dist[node] = 0;
    priority_queue<ii> pq;
    pq.push({-0,node});

    while(!pq.empty()){
        ii cur = pq.top();
        pq.pop();
        if(marked[cur.S]) continue;
        marked[cur.S] = true;
        
        for(auto v : g[cur.S]){
            if(dist[v.F]> dist[cur.S] + v.S){
                dist[v.F]= dist[cur.S] + v.S;
                pq.push({- dist[v.F],v.F});
            }
        }
    } 
}

void solve(){
  cin>>n>>m;
  g.resize(n+1);
  dist.assign(n+1,1e18);
  marked.assign(n+1,false);
  for(int i=0;i<m;i++){
      int a,b,c;
      cin>>a>>b>>c;
      g[a].push_back({b,c});
  }
  int start =1;
  dij(start);

  for(int i=1;i<=n;i++){
      cout<<dist[i]<<" ";
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