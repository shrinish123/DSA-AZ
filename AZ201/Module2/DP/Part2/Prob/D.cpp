#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int n,w;
int dp[101][100100];
int ww[101];
int v[101];

int rec(int lvl,int wt){
    if(lvl == n){
        return 0;
    }

    if(dp[lvl][wt] != -1){
        return dp[lvl][wt];
    }

    //tra
    int ans = rec(lvl+1,wt);
    
    if(wt+ww[lvl] <= w){
       ans = max(ans,v[lvl]+rec(lvl+1,wt+ww[lvl]));
    }

    return dp[lvl][wt] = ans;
   
}

void solve(){
   cin>>n>>w;
   for(int i=0;i<n;i++){
       cin>>ww[i]>>v[i];
   }
   memset(dp,-1,sizeof(dp));
   cout<<rec(0,0)<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}