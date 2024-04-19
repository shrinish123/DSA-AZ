#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int n;
int arr[1001];
int pre[1001];
int dp[1001][1001];

int benefit(int l,int r){
    l++;r++;
    return (pre[r]-pre[l-1])%100;
}

int rec(int l,int r){
    if(l >= r){
        return 0;
    }

    if(dp[l][r] !=-1){
        return dp[l][r];
    }
    int ans =0;
    for(int i=l;i<= r-1;i++){
      ans = max(ans,rec(l,i)+ rec(i+1,r)+ (benefit(l,i)*benefit(i+1,r)));
    }
   
     return dp[l][r] = ans;
}


void solve(){
   cin>>n;

   for(int i=0;i<n;i++){
       cin>>arr[i]; 
   }
   pre[0] =0;
   for(int i=1;i<=n;i++){
    pre[i] = pre[i-1] + arr[i-1];
   }
   memset(dp,-1,sizeof(dp));

   cout<<rec(0,n-1)<<endl;

}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}