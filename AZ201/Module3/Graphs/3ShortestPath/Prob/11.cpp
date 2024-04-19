#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define ii pair<int,int>
#define F first
#define S second

int n,a,b;
vector<int> arr;
vector<vector<ii>> g;
vector<int> dis;
vector<bool> vis;
map<int,vector<int>> mp;

void dij(int src){
    dis[src] = 0;
    priority_queue<ii> pq;
    pq.push({-0,src});

    while(!pq.empty()){
        ii cur = pq.top();
        pq.pop();

        if(vis[cur.S]) continue;
        vis[cur.S] = 1;
         
        for(auto v : g[cur.S]){
            if(dis[v.F]> dis[cur.S]+ v.S){
                dis[v.F]= dis[cur.S]+ v.S;
                pq.push({-dis[v.F],v.F});
            }

        }
    }    
}

void solve(){

  cin>>n>>a>>b;
  arr.resize(n);
  g.resize(n+n);
  dis.assign(n+n,1e18);
  vis.assign(n+n,false);
  for(int i=0;i<n;i++){
      cin>>arr[i];
      if(i+1 <n) g[i].push_back({i+1,b});
      if(i-1 >= 0) g[i].push_back({i-1,b});
      mp[arr[i]].push_back(i);
  }

  int snode= n;
  for(auto v: mp ){
      vector<int> indices = v.S;
      for(auto i : indices){
          g[i].push_back({snode,0});
          g[snode].push_back({i,a});
      }
      snode++;
  }

  int src;
  cin>>src;
  dij(src-1);

  for(int i=0;i<n;i++){
      cout<<dis[i]<<" ";
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