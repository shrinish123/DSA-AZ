#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define ii pair<int,int>
#define F first
#define S second


int n,m,cap;
vector<vector<ii>> g;
vector<int> p;
int dist[10010][111];
int vis[10010][111];

void dij(int st){
    dist[st][0] = 0;

    priority_queue<pair<int,ii>> pq;
    pq.push({-0,{st,0}});

    while(!pq.empty()){
         auto it = pq.top();
         pq.pop();

       

         int node = it.S.F;
         int fuel = it.S.S;
         int cost = -it.F;

         if(vis[node][fuel]) continue;
         vis[node][fuel] = 1;

         
             if(fuel+1 <= cap){
               if(dist[node][fuel+1] > dist[node][fuel] + p[node]){
                   dist[node][fuel+1] = dist[node][fuel] + p[node];
                   pq.push({-dist[node][fuel+1],{node,fuel+1}});
               }
             }
        

         for(auto v : g[node]){
             int neigh= v.F;
             int wt = v.S;
            if(fuel >= wt ){
                if(dist[neigh][fuel-wt] > dist[node][fuel]){
                    dist[neigh][fuel-wt] = dist[node][fuel];
                    pq.push({-dist[neigh][fuel-wt],{neigh,fuel-wt}});
                }
            }
         }
    }
}

void solve(){
   cin>>n>>m;
   g.resize(n+1);
   p.resize(n+1);

   for(int i=0;i<m;i++){
       int a,b,c;
       cin>>a>>b>>c;
       g[a].push_back({b,c});
       g[b].push_back({a,c});
   }

   for(int i=1;i<=n;i++){
    cin>>p[i];
   }


   int st,en;
   cin>>st>>en>>cap;

   for(int i=0;i<=n;i++){
       for(int j=0;j<=cap;j++){
           dist[i][j] = 1e9;
           vis[i][j] = 0;
        }
   }

   dij(st);
   int ans = 1e9;
   for(int i=0;i<=cap;i++){
     ans = min(ans,dist[en][i]);
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