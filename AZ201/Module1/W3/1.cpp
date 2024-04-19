#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F first
#define S second

vector<vector<int>> arr;
vector<vector<int>> vis;
vector<pair<int,int>> cur;
int n,m;
int nodes =0;

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

bool check(int x,int y){
    if(x<0 || x>= n || y<0 || y>= m || arr[x][y] != 0) return 0;
    return 1; 
}
 
void dfs(int i,int j){
    nodes++;
    vis[i][j] =1;
    cur.push_back({i,j});

   for(int k=0;k<4;k++){
     int x = i+dx[k];
     int y = j+ dy[k];
     if(check(x,y) && !vis[x][y]){
         dfs(x,y);
     }
   }

}


void solve(){
      
    cin>>n>>m;
     arr.assign(n,vector<int>(m,0));
     vis.assign(n,vector<int>(m,0));
    nodes =0;
    cur.clear();
  
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            
        }
    }
   

   
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0 && !vis[i][j]){
                nodes =0;   cur.clear();
                dfs(i,j);
                if(nodes != 1){
                   
                    for(auto v : cur){
                    arr[v.F][v.S] = nodes;
                    }
                }
               
            } 
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;
    while(_t--)
    solve();
}