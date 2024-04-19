#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F first
#define S second 
#define  ii pair<int,int>

int n,m;
vector<vector<ii>> g;
vector<int> dis;
int x,y;

void bfs(ii node){
    dis[node.S] = 0;

    priority_queue<ii> q;

    q.push(node);

    while(!q.empty()){
         
         ii cur = q.top();
         q.pop();
        
        for(auto v : g[cur.S]){

            if( dis[v.F] > dis[cur.S] + v.S){
                dis[v.F] = dis[cur.S] + v.S;
                q.push({-dis[v.F], v.F});
            }
        }

    }
    
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
  
    dis.assign(n+1,1e18);

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    
    cin>>x>>y;

    bfs({0,1});

    int aa = dis[x];
   

    dis.assign(n+1,1e18);
    bfs({0,x});
  

    int ab = dis[y];
   
    dis.assign(n+1,1e18);
    bfs({0,y});

    int ac = dis[n];
   


  
        
        if(aa != 1e18 && ab != 1e18  && ac != 1e18  ){
               cout<< aa + ab + ac<<endl;
        }
         else{
            //  cout<<aa<<" "<<ab<<" "<<ac<<endl;
             cout<<-1<<endl;
         }
      

   

}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    solve();
}