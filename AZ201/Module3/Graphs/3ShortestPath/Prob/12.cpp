#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define ii pair<int,int>
#define F first
#define S second


int n,m;
vector<string> grid;
int dis[1010][1010];

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

bool check(int x,int y){
    if(x < 0 || x >= n || y< 0 || y>= m  || grid[x][y] == '#') return 0;
    return 1;
}

bool checkpunch(int x,int y){
    if(x < 0 || x >= n || y< 0 || y>= m  || grid[x][y] == '.') return 0;
    return 1;
}

void bfs(ii st){
   dis[st.F][st.S]=0;

   deque<ii> dq;
   dq.push_back(st);

   while(!dq.empty()){
       ii cur = dq.front();
       dq.pop_front();

       for(int i=0;i<4;i++){
          ii neigh = {cur.F+dx[i],cur.S+dy[i]};

          if(check(neigh.F,neigh.S) && dis[neigh.F][neigh.S] > dis[cur.F][cur.S]){
              dis[neigh.F][neigh.S] = dis[cur.F][cur.S];
              dq.push_front(neigh);
          }
          else if(checkpunch(neigh.F,neigh.S)){
             
              int x = neigh.F; int y= neigh.S;
              for(int p = x-1;p <=x+1;p++){
                  for(int q = y-1;q <=y+1;q++){
                      if(p>=0 && p< n && q>= 0 && q < m ){
                          if( dis[p][q] > dis[cur.F][cur.S] +1) {
                              dis[p][q] = dis[cur.F][cur.S] +1;
                              dq.push_back({p,q});
                             
                          }
                      }
                  }
              }


          }
       }
   }
}

void solve(){
   cin>>n>>m;
   grid.resize(n);
   for(int i=0;i<n;i++){
       cin>>grid[i];
       for(int j=0;j<m;j++){

       }
   }

   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           dis[i][j] = 1e18;
       }
   }
   ii st = {0,0};
   ii en = {n-1,m-1};


   bfs(st);

   

   cout<<dis[en.F][en.S]<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
    solve();
}