#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int n;
int arr[510];
int pre[510];
int dp[501][501];

int bene(int l,int r){
    l++;r++;
    return (pre[r] - pre[l-1])%100;
}


int rec(int l,int r){
    if( l >= r){
        return 0;
    }

    if(dp[l][r] != -1){
        return dp[l][r];
    }

    int ans =1e9;

    for(int x = l;x<r; x++){
        ans = min(ans, rec(l,x) + rec(x+1,r) + (bene(l,x) * bene(x+1,r)));
    }

    return dp[l][r] = ans;

}

void solve(){
   cin>>n;
   pre[0] = 0;
   for(int i=0;i<n;i++){
       cin>>arr[i];
      if(i) pre[i] = pre[i-1] + arr[i-1]; 
   }
   pre[n] = pre[n-1] + arr[n-1];

   memset(dp,-1,sizeof(dp));

   cout<<rec(0,n-1)<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}