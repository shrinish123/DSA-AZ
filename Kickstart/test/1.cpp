#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int,int>
#define F first
#define S second

int arr[1510][1510];
int dist[1510][1510];

int n,m;

bool check(int x,int y){
    if( x< 0 || x>= n || y< 0 || y>= m )return 0;
    return 1;
}


void bfs(ii start){
   
   dist[start.F][start.S] = 0;

   queue<ii> q;
   q.push(start);

   while(!q.empty()){
       ii cur = q.front();
       q.pop();

       ii neigh[] = { {cur.F + arr[cur.F][cur.S],cur.S},{cur.F , cur.S + arr[cur.F][cur.S]}};

       for(int i=0;i<2;i++){
           if( check(neigh[i].F,neigh[i].S) && dist[neigh[i].F][neigh[i].S] > dist[cur.F][cur.S] +1){
               dist[neigh[i].F][neigh[i].S] = dist[cur.F][cur.S] +1;
               q.push(neigh[i]);
           }
       } 
   }
}

void solve(){
    
   
    cin>>n>>m;

  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin>>arr[i][j];
        dist[i][j] = 1e18;
      }
  }

  bfs({0,0});

  if(dist[n-1][m-1] != 1e18){
      cout<<dist[n-1][m-1]<<endl;
  }else {
      cout<<-1<<endl;
  }

}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int _t;cin>>_t;while(_t--)
    solve();
}