#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define ii pair<int,int>
#define F first
#define S second

int n,k;

vector<vector<int>> grid;
vector<vector<int>> vis;
vector<string> g;

vector<vector<ii>> conn;
vector<ii> comp;
int nodeVis = 0;

int dx[] ={1,0,-1,0};
int dy[] ={0,-1,0,1};

bool isValid(int parx,int pary,int x,int y){
    if(x < 0 || x>= n  || y<0 || y>= 10 || grid[x][y] == 0 || grid[parx][pary] != grid[x][y] ) return 0;
    return 1;
}

void dfs(ii node){
    vis[node.F][node.S] = 1;
    nodeVis++;
    comp.push_back(node);

    for(int i=0;i<4;i++){
        ii neigh = {node.F+dx[i],node.S+dy[i]};

        if(isValid(node.F,node.S,neigh.F,neigh.S) && !vis[neigh.F][neigh.S]){
           dfs(neigh);
        }
    }
}

void findConn(){
   for(int i=0;i<n;i++){
      for(int j=0;j<10;j++){
         if(!vis[i][j] &&  grid[i][j] !=0){
             ii node = {i,j};
             nodeVis = 0;
             dfs(node);
             if(nodeVis >= k){
                conn.push_back(comp);
             }
             comp.clear();
             
         }
      }
  }
   vis.assign(n,vector<int> (10,0));
}

void makezeros(){
    for(auto v:conn){
        for(auto p : v){
            grid[p.F][p.S] = 0;
        }
    }
}

void addGravity(){
   
    for(int j=0;j<10;j++){
        int i=n-1;
        int gr = n-1;
        while(i>=0){
            if(grid[i][j] == 0){
                i--;
              
            }
            else {
               
              grid[gr][j] = grid[i][j];  
              if(gr != i)grid[i][j] =0;
              gr=gr-1;
              i--;
            
            }
        }
    }


}

void solve(){
  cin>>n>>k;
  g.resize(n);
  grid.assign(n,vector<int> (10,0));
  vis.assign(n,vector<int> (10,0));

  for(int i=0;i<n;i++){
      for(int j=0;j<10;j++){
          vis[i][j]=0;
      }
  }

  
  for(int i=0;i<n;i++){
      cin>>g[i];
  }
   for(int i=0;i<n;i++){
      for(int j=0;j<10;j++){
          grid[i][j] = g[i][j]-'0';
      }
  }



  findConn();

  while(!conn.empty()){

      conn.clear();
      findConn();
      makezeros();
      addGravity();

  }

  // ans
  for(int i=0;i<n;i++){
      for(int j=0;j<10;j++){
          cout<<grid[i][j];
      }
      cout<<endl;
  }
   cout<<endl;

}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   
    solve();
}

// https://www.learning.algozenith.com/problems/Vertical-Grid-389