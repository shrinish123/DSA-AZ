#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int mod = 100000000;

int n1,n2,k1,k2;
int dp[101][101][11][3];

int rec(int n,int m, int c1,int pre){
    if(n == n1 && m == n2){
        return 1;
    }

    if(dp[n][m][c1][pre] != -1){
        return dp[n][m][c1][pre];
    }
    int ans =0;

    if(pre == 1){
       if(n+1 <= n1 && c1+1 <= k1) ans = (ans + rec(n+1,m,c1+1,1))%mod;
       if(m+1 <= n2 ) ans = (ans + rec(n,m+1,1,2))%mod;
     
    }else if(pre == 2){
     if(n+1 <= n1)  ans = (ans + rec(n+1,m,1,1))%mod;
     if(m+1<= n2 && c1+1 <=k2)  ans = (ans + rec(n,m+1,c1+1,2))%mod;
    }else {
      if(n+1 <= n1) ans = (ans + rec(n+1,m,1,1))%mod;
      if(m+1 <= n2)  ans = (ans + rec(n,m+1,1,2))%mod;
    }

    return dp[n][m][c1][pre] = ans;
}


void solve(){
  cin>>n1>>n2>>k1>>k2;
  for(int i=0;i<=n1;i++){
      for(int j=0;j<=n2;j++){
          for(int k = 0;k<=max(k1,k2);k++){
                  for(int m= 0;m<3;m++){
                      dp[i][j][k][m] =-1;
                  }
              
          }
      }
  }

  cout<<rec(0,0,0,0)<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}