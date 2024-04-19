#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

#define ii pair<int,int>
#define F first
#define S second

vector<string> arr;
ii dist[1010][1010];
ii par[1010][1010];

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
int n,m;

bool inside(int x,int y){
   if(x<0 || x>= n || y<0 || y>= m || arr[x][y]== '#') return 0;
   return 1;
}

void bfs(ii st){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j].F = 1e9;
        }
    }

    dist[st.F][st.S].F = 0;
    dist[st.F][st.S].S = 1;

    queue<ii> q;
    q.push(st);
    

    while(!q.empty()){
        ii cur = q.front();
        q.pop();
        int curd = dist[cur.F][cur.S].F;
        
        for(int i=0;i<4;i++){
            ii neigh = {cur.F+dx[i],cur.S+dy[i]};
            if(inside(neigh.F,neigh.S) && dist[neigh.F][neigh.S].F > curd+1){
                 dist[neigh.F][neigh.S].F = curd+1;
                dist[neigh.F][neigh.S].S = dist[cur.F][cur.S].S;
                 par[neigh.F][neigh.S]= cur;
                 q.push(neigh);
            }else if(inside(neigh.F,neigh.S) && dist[neigh.F][neigh.S].F == curd+1){
                 dist[neigh.F][neigh.S].S += dist[cur.F][cur.S].S;
            }
        }

    }
}

void solve(){
   
   cin>>n>>m;
   ii st,en;
   arr.resize(n);
   for(int i=0;i<n;i++){
       cin>>arr[i];
       for(int j=0;j<m;j++){
         if(arr[i][j] == 'S'){
             st = {i,j};
         }else if(arr[i][j]== 'E'){
             en= {i,j};
         }
       }
   }
   bfs(st);
   cout<<dist[en.F][en.S].F<<" "<<dist[en.F][en.S].S<<endl;

   ii temp = en;
   vector<ii> path;
   while(temp !=st){
       path.push_back(temp);
       temp = par[temp.F][temp.S];
   }
   path.push_back(st);
   reverse(path.begin(),path.end());

   for(auto v : path){
       cout<<v.F<<" "<<v.S<<endl;
   }
   cout<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
    solve();
}

// no of shortest paths

/*
6 6
S.#...
......
####.#
E.##.#
..#..#
#....#
*/