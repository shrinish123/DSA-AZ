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

void bfs(int st){
    dis[st] = 0;
    queue<int> q;
    q.push(st);

    while(!q.empty()){
        int cur = q.front();
       
        q.pop();
        for(auto v : g[cur]){
            int curd = dis[cur];
            int weigh = v.S;
            if(dis[v.F] > curd + weigh){
                   dis[v.F] = curd + weigh;
                   q.push(v.F);
            }
        }
    }

}

void solve(){
  cin>>n>>m;

  g.resize(n+1);
  dis.assign(n+1,1e9);

  for(int i=0;i<m;i++){
      int a,b,c;
      cin>>a>>b>>c;

      g[a].push_back({b,c});
      g[b].push_back({a,c});
  }
  int st;
  cin>>st;
  bfs(st);

  for(int i=1;i<=n;i++){
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


// same as dijkstra except just use a prority queue