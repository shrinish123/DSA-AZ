#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define ii pair<int,int>
#define F  first
#define S second

int n,m;
vector<string> arr; 
int ans =0;

int vis[1010][1010];

int dx[] = {1,0,-1,0};
int dy[] ={0,-1,0,1};

bool isValid(int x,int y){
    if(x <0 || x>= n || y<0 || y>=m || arr[x][y] == '#') return 0;
    return 1; 
}

void dfs(ii node){
    vis[node.F][node.S]= 1;

    for(int i=0;i<4;i++){
        ii neigh = {node.F+dx[i],node.S+dy[i]};
        if(isValid(neigh.F,neigh.S) && !vis[neigh.F][neigh.S]){
            dfs(neigh);
        }
    }
}

void solve(){
   cin>>n>>m;
   arr.resize(n);
   for(int i=0;i<n;i++){
       cin>>arr[i];
   }

   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           vis[i][j] =0;
       }
   }

   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           if(vis[i][j] == 0 && arr[i][j] == '.'){
               ii node = {i,j};
               ans++;
               dfs(node);
           }
       }
   }

   cout<<ans<<endl;

}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
    solve();
}

//   https://www.learning.algozenith.com/problems/Find-the-Number-of-Rooms-178