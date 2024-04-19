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


void dijkstra(ii st){

    dist[st.S] = 0;
    priority_queue<ii> pq;
    pq.push(st);

    while(!pq.empty()){
        ii cur = pq.top();
        pq.pop();

        for(auto v: g[cur.S]){
            
           int neigh = v.F;
           int wt = v.S;
           if(dist[v.F] > dist[cur.S] + wt){
               dist[v.F] = dist[cur.S] + wt;
               pq.push({-dist[neigh],v.F});
           }
        }
    }
}

void solve(){
   cin>>n>>m;
   g.resize(n+1);
   dist.assign(n+1,1e9);

   for(int i=0;i<m;i++){
       int a,b,c;
       cin>>a>>b>>c;
       g[a].push_back({b,c});
       g[b].push_back({a,c});
   }

   int st;
   cin>>st;
   ii node = {0,st};
   dijkstra(node);

   for(auto v : dist){
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