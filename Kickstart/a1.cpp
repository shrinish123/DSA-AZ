#include<bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int> 
#define F first
#define S second

int n;
int dist[1010][1010];

int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};

bool check(int x,int y){
    if(x< 0 || x>= n || y<0 || y>=n )return false;
    return true;
}

void bfs(ii start){

    dist[start.F][start.S] = 0;
    queue<ii> q;
    q.push({start});

    while(!q.empty()){

        ii cur = q.front();
        q.pop();

        for(int i=0;i<8;i++){
            ii neigh = {cur.F + dx[i],cur.S+dy[i]};
            if( check(neigh.F,neigh.S) && dist[neigh.F][neigh.S] > dist[cur.F][cur.S] +1){
                dist[neigh.F][neigh.S] = dist[cur.F][cur.S] +1;
                q.push(neigh);
            }
        }
    }
}

void solve(){
    cin>>n;
    
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    ii start = {a,b};

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j] = 1e18;
        }
    }
    
    bfs(start);

    if( dist[c][d] == 1e18){
        cout<<-1<<endl;
    }else{
        cout<<dist[c][d]<<endl;
    }
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}