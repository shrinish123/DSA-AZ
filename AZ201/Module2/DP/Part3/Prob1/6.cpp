#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int grid[1001][1001];
int dp[1001][1001];

int n,m;

int rec(int i,int j){

    if(i< 0 || j< 0 ) return 0;


    if(i==0 && j==0 ){
        if(grid[i][j] == 1)  return 1;
        else return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans =0;

    if(grid[i][j]){
        ans = min({rec(i,j-1),rec(i-1,j),rec(i-1,j-1)}) + 1;

    }else {
        ans =0;
    }
    
    return dp[i][j] = ans;
}

void solve(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          cin>>grid[i][j];
          dp[i][j] = -1;
      }
  }
  int ans =0;
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          ans = max(ans,rec(i,j));
          
      }
  }
  cout<<ans*ans<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}