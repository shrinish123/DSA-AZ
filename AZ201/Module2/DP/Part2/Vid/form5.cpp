#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int dp[100100];
int k;
int n;
int arr[20002];


int rec(int x){

    if(x ==0){
        return  0;
    }

    if(dp[x] != -1){
      return  dp[x];
    }
    int ans =0;
    for(int i=0;i<n;i++){
        if(x >= arr[i]  && !rec(x-arr[i])){
            ans =1;
        }
    }

    return dp[x] = ans;
}

void solve(){
   cin>>n>>k;
   memset(dp,-1,sizeof(dp));
   for(int i=0;i,n;i++){
       cin>>arr[i];
   }
   cout<<rec(k)<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}