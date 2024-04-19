#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n,m;

vector<vector<int>> g;
vector<int> dis;


void bfs(int node){

    for(auto i=1;i<=n;i++){
        dis[i]= 1e9;
    }

   dis[node]=0;
   
   queue<int> q;
   q.push(node);

   while(!q.empty()){
       int cur = q.front();
       q.pop();
       for(auto v: g[cur]){
           if(dis[v] == 1e9 ){
               dis[v] = dis[cur]+1;
               q.push(v);
           }
       }
   }

}

void solve(){
   cin>>n>>m;
   g.clear();
   g.resize(n+1);
   dis.assign(n+1,0);

  for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;

      g[a].push_back(b);
      g[b].push_back(a);
  }
  int st,en;
  cin>>st>>en;
  bfs(st);
   
   cout<<dis[en]<<endl;

}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
    solve();
}

// bfs on expliict graph

/*
6 6
S.#...
......
####.#
E.##.#
..#..#
#....#
*/