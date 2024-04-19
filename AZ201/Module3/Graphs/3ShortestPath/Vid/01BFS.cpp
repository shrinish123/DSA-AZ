#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n,m;
vector<vector<pair<int,int>>> g;
vector<int> dis;

void bfs(int sc){

    deque<int> dq;
    dis.assign(n+1,1e9);
    dis[sc]= 0;

    dq.push_back(sc);

    while(!dq.empty()){
        int cur = dq.front();
        dq.pop_back();

        for(auto v :g[cur]){
            int neigh = v.first;
            int weigh = v.second;
            if(dis[neigh] > dis[cur] + weigh){
                dis[neigh] = dis[cur] +weigh;
                if(weigh == 0){
                       dq.push_front(neigh);
                }else {
                     dq.push_back(neigh);
                }
              
            }
        }
    }

}

void solve(){
   cin>>n>>m;
   for(int i=0;i<m;i++){
       int a,b,c;
       cin>>a>>b>>c;
       g[a].push_back({b,c});
       g[b].push_back({a,c});
   }

   int sc;
   cin>>sc;
   bfs(sc);


}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
    solve();
}


// Simpl 01 BFS Implementation
// can be used for multisocurce 01 too with only pushing all sources together