#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define ii pair<int,int>
#define F first
#define S second

int n;
vector<string> arr; 
vector<vector<int>> vis;
int nodeVis =0;
vector<pair<int,vector<ii>>>  conn;
vector<pair<int,vector<ii>>>  finconn;
vector<ii> comp;
vector<ii> perarea;

int dx[]= {1,0,-1,0};
int dy[] ={0,-1,0,1};

bool isValid(int x,int y){
    if(x< 0 || x>= n || y<0|| y>= n || arr[x][y] != '#') return 0;
    return 1;
}

void dfs(ii node){
    vis[node.F][node.S] = 1;
    nodeVis++;
    comp.push_back(node);

    for(int i=0;i<4;i++){
        ii neigh = {node.F+dx[i],node.S+dy[i]};

        if(isValid(neigh.F,neigh.S) && !vis[neigh.F][neigh.S]){
            dfs(neigh);
        }
    }
}

void solve(){
   cin>>n;
   arr.resize(n);
   vis.assign(n,vector<int> (n,0));
   for(int i=0;i<n;i++){
       cin>>arr[i];
   }

   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           if(arr[i][j] == '#' && !vis[i][j]){
               nodeVis=0;
               ii node = {i,j};
               dfs(node);
               conn.push_back({nodeVis,comp});
               comp.clear();
           }
       }
   }

   sort(conn.rbegin(),conn.rend());

   for(int i=0;i<conn.size();i++){
       if(i==0) finconn.push_back(conn[i]);
       else if(conn[i].F == conn[0].F)  finconn.push_back(conn[i]);
   }

   for(int i=0;i<finconn.size();i++){
       int area = finconn[i].F;
       vector<ii> nodes = finconn[i].S;
       int totdel= 0;

       for(auto v: nodes){
           for(int i=0;i<4;i++){
               ii neigh = {v.F+dx[i],v.S+dy[i]};
               if(isValid(neigh.F,neigh.S)) totdel++;
           }
       }
       int per = area*4 - totdel;
       perarea.push_back({per,area});
   }

   sort(perarea.begin(),perarea.end());

   cout<<perarea[0].S<<" "<<perarea[0].F<<endl;
   
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
    solve();
}
 
//  https://www.learning.algozenith.com/problems/Area-and-Perimeter-of-Connected-Components-396
