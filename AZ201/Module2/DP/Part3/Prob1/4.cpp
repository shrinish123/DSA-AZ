#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int mod = 1000000000+7;

int n,m,k;
int dp[2001][2001];

int rec(int l,int cnt){
    if(l == n-1){
        if(cnt == 0){
       
            return 1;
        }else {
            return 0;
        }
    }
    
    if(dp[l][cnt] != -1){
       
        return dp[l][cnt];

    }
    int ans =rec(l+1,cnt)%mod;
    
        if(cnt > 0){
           ans = (ans + (rec(l+1,cnt-1)*(m-1))%mod)%mod;
        }
    
    return dp[l][cnt] = ans;
}


void solve(){
   cin>>n>>m>>k;
   for(int i=0;i<=n;i++){
       for(int j=0;j<=k;j++){
           dp[i][j] = -1;
       }
   }
   int ans  = (rec(0,k) *m)%mod;
   cout<<ans<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}