#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int x[101];
int y[101];
int dp[101][101];
int n;

int sq(int x){
    return x*x;
}

int dist(int i,int j){
  return  sq(x[i] - x[j]) + sq(y[i]  - y[j]);
}

int rec(int l,int r){
    if(r- l < 3){
        return 0;
    }

    if(dp[l][r] !=-1){
        return dp[l][r];
    }
    int ans =1e9;
    ans = min(ans,rec(l,r-1)+ dist(l,r-1));
    ans = min(ans,rec(l+1,r)+ dist(l+1,r));

    for(int x = l+2;x<=r-2;x++){
        ans = min(ans, rec(l,x)+ rec(x,r) + dist(l,x) + dist(x,r));
    }

    return dp[l][r] = ans;
}

void solve(){
  cin>>n;
  for(int i=0;i<n;i++){
      cin>>x[i]>>y[i];
  }
  memset(dp,-1,sizeof(dp));
  cout<<rec(0,n-1)<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}