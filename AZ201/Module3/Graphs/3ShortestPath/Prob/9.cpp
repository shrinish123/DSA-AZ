#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define ii pair<int,int>
#define F first
#define S second

const int MOD = 1e9 +7;
int n,m;
vector<vector<ii>> g;

vector<int> cost;
vector<bool> vis;
vector<int> routes;
vector<int> minf;
vector<int> maxf; 

void dij(int node){

    cost[node] = 0;
    routes[node] = 1;
    minf[node] = 0;
    maxf[node] = 0;
    priority_queue<ii> pq;
    pq.push({-0,node});

    while(!pq.empty()){
        ii cur = pq.top();
        pq.pop();

        if(vis[cur.S]) continue;
        vis[cur.S] = 1;

        for(auto v : g[cur.S]){
            int neigh = v.F;
            int wt = v.S;

            if(cost[neigh] > cost[cur.S]+ wt){
                cost[neigh] = cost[cur.S]+ wt;

                  routes[neigh] = routes[cur.S];
                  minf[neigh] = minf[cur.S]+ 1;
                  maxf[neigh] = maxf[cur.S]+ 1;

                pq.push({-cost[neigh],neigh});
               
                

            }
            else if(cost[neigh] == cost[cur.S]+ wt){

                  routes[neigh] = (routes[neigh] + routes[cur.S])%MOD;

                   if(minf[neigh] > minf[cur.S]+ 1){
                    minf[neigh] = minf[cur.S]+ 1;
                   }
                if(maxf[neigh] < maxf[cur.S]+1){
                    maxf[neigh] = maxf[cur.S]+ 1;
                }

            }

        }
    }

}

void solve(){
  cin>>n>>m;
  g.resize(n+1);
  cost.assign(n+1,1e18);
  vis.assign(n+1,false);
  routes.assign(n+1,0);
  minf.assign(n+1,1e18);
  maxf.assign(n+1,0);

  for(int i=0;i<m;i++){
      int a,b,c;
      cin>>a>>b>>c;
      g[a].push_back({b,c});
  }

  dij(1);
   if(cost[n] == 1e18){
       cout<<-1<<endl;
   }else {
       cout<<cost[n]<<" "<<routes[n]<<" "<<minf[n]<<" "<<maxf[n]<<endl;
   }
 
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
    solve();
}