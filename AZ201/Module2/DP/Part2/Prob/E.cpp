#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int n,w;
int ww[101];
int vv[101];
int dp[101][100100];

int rec(int lvl,int v){
    if(lvl == n){
       if(v == 0){
           return 0;
       }else {
           return 1e15;
       }
    }

    if(dp[lvl][v] != -1){
        return dp[lvl][v];
    }

    // tra

    int ans = rec(lvl+1,v);

    if(v -vv[lvl] >= 0){
          ans = min(ans, ww[lvl] + rec(lvl+1,v - vv[lvl]));
    }
  

    return dp[lvl][v] = ans;
}

void solve(){
   cin>>n>>w;
   for(int i=0;i<n;i++){
       cin>>ww[i]>>vv[i];
   }
   memset(dp,-1,sizeof(dp));
 
   int ans =0;
   for(int i=0;i<100100;i++){
       if(rec(0,i) <= w && rec(0,i) >=0){
          ans = i;
        
       }
      
   }

   cout<<ans<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}