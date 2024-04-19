#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

#define ii pair<int,int> 
#define  F first
#define S second

int h,w;
vector<string> arr;
int dp[1001][1001];

int dx[] = {1,0-1,0};
int dy[] ={0,-1,0,1};

bool check(int x,int y){
    if(x<0 || x>= h || y<0 || y>= w || arr[x][y] == '#') return 0;
    else return 1;
}

int rec(ii node,ii prev){


// basecase 

   if(node.F == h-1 && node.S == w-1) return 1;

    bool t =0;
    for(int i=0;i<4;i++){
        ii neigh = {node.F+ dx[i],node.S+dy[i]};

        if(check(neigh.F,neigh.S) && neigh != prev) t =1;
    }
    if(!t) return 0;
   


    if(dp[node.F][node.S] != -1){
        return dp[node.F][node.S];
    }
    int ans =0;
    for(int i=0;i<4;i++){
       ii neigh = {node.F+ dx[i],node.S+dy[i]};

       if(check(neigh.F,neigh.S) && neigh != prev){
          ans += rec(neigh,node);
       }
    }

    return dp[node.F][node.S] = ans;
  
}

void solve(){
    cin>>h>>w;
    arr.resize(h);
    for(int i=0;i<h;i++){
        cin>>arr[i];
    }
   memset(dp,-1,sizeof(dp));
   cout<< rec({0,0},{-1,-1})<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}