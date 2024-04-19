#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define ii pair<int,int>
#define F first
#define S second 

int distP[1010][1010];
int mon[1010][1010];
int n,m;

int dx[] = {1,0,-1,0};
int dy[]= {0,-1,0,1};


vector<string> arr;
vector<ii> monpos;
vector<ii> edges;

bool check(int x,int y){
    if(x < 0 || x >= n || y< 0 || y>= m || arr[x][y] == '#') return 0;
    return 1;
}

void bfs(ii st){
    distP[st.F][st.S] = 0;

    queue<ii> q;
    q.push(st);

    while(!q.empty()){
        ii cur  = q.front();
        q.pop();
         
        for(int i=0;i<4;i++){
            ii neigh = {cur.F+dx[i],cur.S+dy[i]};

            if(check(neigh.F,neigh.S) && distP[neigh.F][neigh.S] > distP[cur.F][cur.S]+1){
                distP[neigh.F][neigh.S] = distP[cur.F][cur.S]+1;
                q.push(neigh);
            }
        }
    }
}

void multibfs(){
       queue<ii> q;

    for(auto v : monpos){
       mon[v.F][v.S] = 0;
        q.push(v);
    }

    while(!q.empty()){
        ii cur  = q.front();
        q.pop();
         
        for(int i=0;i<4;i++){
            ii neigh = {cur.F+dx[i],cur.S+dy[i]};

            if(check(neigh.F,neigh.S) && mon[neigh.F][neigh.S] > mon[cur.F][cur.S]+1){
                mon[neigh.F][neigh.S] = mon[cur.F][cur.S]+1;
                q.push(neigh);
            }
        }
    }
}

void solve(){
   cin>>n>>m;
   arr.resize(n);
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           distP[i][j] = 1e9;
           mon[i][j] = 1e9;
       }
   }
   ii st;
   for(int i=0;i<n;i++){
       cin>>arr[i];
       for(int j=0;j<m;j++){
           if(arr[i][j] == 'A'){
               st = {i,j};
           }
            if(arr[i][j] == 'M'){
               monpos.push_back({i,j});
           }
           if((i == 0 || i == n-1 || j== 0 || j== m-1) && (arr[i][j] == '.' || arr[i][j] == 'A')){
               edges.push_back({i,j});
           }
       }
   }

   bfs(st);
   multibfs();

   int ans = 1e9;
    
   for(auto v :edges ){
       if(distP[v.F][v.S] < mon[v.F][v.S]){
        
           ans = min(ans,distP[v.F][v.S]);
         
       }
   }

   if(ans != 1e9){
       cout<<"YES"<<endl;
       cout<<ans<<endl;
   }else {
       cout<<"NO"<<endl;
   }

   
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
    solve();
}