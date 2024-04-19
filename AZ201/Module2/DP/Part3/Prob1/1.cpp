#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int mod = 1000000000 +7;

int n,m;
int grid[1001][1001];
int dp[1001][1001];

bool check(int i,int j){
    if(i< 0 || i>=n || j<0 || j>= m) return 0;
    return 1;
}

int rec(int i,int j){
    if(!check(i,j) ){
        return 0;
    }
    if(grid[i][j] == 1 ){
        return 0;
    }

    if(i==0 &&  j==0){
        return 1;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans =0;

    ans = (rec(i-1,j) + rec(i,j-1))%mod;

    return dp[i][j] =ans;
}

void solve(){
   cin>>n>>m;
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           cin>>grid[i][j];
           dp[i][j] =-1;
       }
   }
   
   cout<<rec(n-1,m-1)<<endl;

}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}