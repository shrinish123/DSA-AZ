#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
int n,m;
vector<vector<int>> g;
vector<vector<int>> rev;
vector<int> dis;

void bfs(int st){
    dis[st] = 0;
     deque<int> dq;

     dq.push_back(st);

     while(!dq.empty()){
         int cur = dq.front();
         dq.pop_front();

         for(auto v : g[cur]){
             if(dis[v] > dis[cur]){
                 dis[v] = dis[cur];
                 dq.push_front(v);
             }
         }
         for(auto v : rev[cur]){
            if(dis[v] > dis[cur]+1){
                 dis[v] = dis[cur]+1;
                 dq.push_back(v);
             }
         }

     }
}

void solve(){
   cin>>n>>m;
   g.clear();
   rev.clear();
   dis.clear();
   g.resize(n+1);
   rev.resize(n+1);
   dis.assign(n+1,1e18);

  map<pair<int,int>,int> edcount;
   for(int i=0;i<m;i++){
       int a,b;
       cin>>a>>b;
       if(a == b) continue;
       int tempa = a;
       int tempb = b;
       if(tempa> tempb ) swap(tempa,tempb);
       edcount[{tempa,tempb}]++;

       if( edcount[{tempa,tempb}] == 1){
          g[a].push_back(b);
          rev[b].push_back(a);
       }
   }

   bfs(1);

  if(dis[n] != 1e18) cout<<dis[n]<<endl;
  else cout<<-1<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    string temp;getline(cin,temp);

    while(t--) 
    solve();
}