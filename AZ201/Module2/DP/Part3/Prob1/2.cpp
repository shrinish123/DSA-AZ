#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int n,m;
int arr[1001][1001];
int dp[1001][1001];

bool check(int i,int j){
    if(i< 0 || i>= n || j< 0 || j>= m) return 0;
    return 1;
}

int rec(int i,int j){
    if(!check(i,j)){
        return 0;
    }

    if(i== n-1 && j == m-1){
        return arr[i][j];
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = arr[i][j];

    ans = max(ans+rec(i+1,j),ans+rec(i,j+1));

    return dp[i][j] =ans;
}

void solve(){
   cin>>n>>m;
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           cin>>arr[i][j];
           dp[i][j] = -1;
       }
   }

   cout<<rec(0,0)<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}