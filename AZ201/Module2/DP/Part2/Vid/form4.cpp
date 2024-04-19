#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int n;
int arr[2002];
int dp[2002][2002];
int saved[2002][2002];

int rec(int l,int r){
    if(l ==r){
        return arr[l];
    }

    if(saved[l][r] ){
        return dp[l][r];
    } 

    int ans = 0;

    ans = max(arr[l] -rec(l+1,r),arr[r] - rec(l,r-1)) ;
    
    saved[l][r] =1;
   return dp[l][r] = ans;

}


void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    memset(saved,0,sizeof(saved));
    cout<<rec(0,n-1)<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}