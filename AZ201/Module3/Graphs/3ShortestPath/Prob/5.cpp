#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define ii pair<int,int>
#define F first
#define S second 

int n,m;
vector<vector<ii>> g;

vector<int> dis;
vector<bool> marked;
vector<pair<ii,int>> edges;  
vector<int> timed;

void dij(int node){
    dis[node] = 0;

    priority_queue<ii> pq;
    pq.push({-0,node});

    while(!pq.empty()){
        ii cur = pq.top();
        pq.pop();

        if(marked[cur.S]) continue;
        marked[cur.S] = true;

        for(auto v : g[cur.S]){
            
            if(dis[v.F] > dis[cur.S] + v.S){
                dis[v.F] = dis[cur.S] + v.S;
                pq.push({-dis[v.F],v.F});
            }
        }
    }
}

void solve(){
  cin>>n>>m;
  g.resize(n+1);
  dis.assign(n+1,1e18);
  dis[0] = 0;
  marked.assign(n+1,false);

  for(int i=0;i<m;i++){
      int a,b,c;
      cin>>a>>b>>c;
      g[a].push_back({b,c});
      g[b].push_back({a,c});
      edges.push_back({{a,b},c});
  }
  int node;
  cin>>node;
  dij(node);

 for(auto v : edges){
     int a = v.F.F;
     int b = v.F.S;
     int wt =v.S;
     int tim =0;
      tim = (dis[a] + dis[b] + wt)*5;
      timed.push_back(tim);
 }

            int ans = 0;

            for(auto v : timed){
                ans = max(ans, v);
            }

            
            cout<<ans<<endl;

}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
    solve();
}