#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define ii pair<int,int>
#define F first
#define S second 

int n,m;
int grid[1010][1010];
int dist[1010][1010];

int dx[] = {5,0,0,1,-1};
int dy[]= {5,1,-1,0,0};

bool check(int x,int y){
    if(x< 0 || x>= n || y< 0 || y>= m) return 0;
    return 1;
}

void bfs(ii st){
    dist[st.F][st.S] = 0;

    deque<ii> dq;
    dq.push_back(st);

    while(!dq.empty()){
        ii cur = dq.front();
        dq.pop_front();

        for(int i=1;i<=4 ;i++){
            ii neigh = {cur.F + dx[i],cur.S+ dy[i]};
            if(check(neigh.F,neigh.S)){
                if(grid[cur.F][cur.S] == i && dist[neigh.F][neigh.S] > dist[cur.F][cur.S]){
                    dist[neigh.F][neigh.S] = dist[cur.F][cur.S];
                    dq.push_front(neigh);
            }
            else if(grid[cur.F][cur.S] != i &&  dist[neigh.F][neigh.S] > dist[cur.F][cur.S] +1){
                 dist[neigh.F][neigh.S] = dist[cur.F][cur.S] +1;
                 dq.push_back(neigh);
            }
            }
           
        }
    }
}

void solve(){
   cin>>n>>m;
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           cin>>grid[i][j];
        dist[i][j] = 1e18;
       }
   }
   bfs({0,0});

   cout<<dist[n-1][m-1]<<endl;

}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
    solve();
}