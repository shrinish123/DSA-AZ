#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int n;
int a[100100];
int b[100100];
int c[100100];
int dp[100100][4];

int rec(int lvl,int act){
   
   if(lvl == n){
       return 0;
   }

   if(dp[lvl][act] != -1){
       return dp[lvl][act];
   }

   // 
   int ans =0;

   if(act == 1){
       ans = max(a[lvl]+ rec(lvl+1,2),a[lvl]+ rec(lvl+1,3));

   }else if(act ==2){
       ans = b[lvl] + max(rec(lvl+1,1),rec(lvl+1,3));
   }else {
      ans = c[lvl] + max(rec(lvl+1,1),rec(lvl+1,2));
   }

   return dp[lvl][act] = ans;
}



void solve(){
  cin>>n;
  for(int i=0;i<n;i++){
      cin>>a[i]>>b[i]>>c[i];
  }

  memset(dp,-1,sizeof(dp));
  int ans =max({rec(0,1),rec(0,2),rec(0,3)});
  cout<<ans<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}