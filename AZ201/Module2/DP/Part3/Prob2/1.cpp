#include<bits/stdc++.h>
using namespace std;

#define int long long
int n,m,k;
int dp[210][210][410];
int arr[210][210];
int mod = 1e9+7;

bool check(int i,int j){

    if(i<0 || i>= n || j<0  || j>= m ) return 0;
    else return 1;
}

int rec(int i,int j,int l){

    if(i == n-1 && j == m-1){
        return 1;
    }

    if(dp[i][j][l] != -1){
        return dp[i][j][l];
    }

    int ans =0;

    if(check(i+1,j) ){
       
       if(arr[i+1][j] ==0 ){
           ans = (ans + rec(i+1,j,l))%mod;
       }else if(arr[i+1][j] == 1 && l>0){
           ans = (ans +  rec(i+1,j,l-1))%mod;
       }
    }

    if(check(i,j+1)){
    
       if(arr[i][j+1] ==0 ){
           ans = (ans +  rec(i,j+1,l))%mod;
       }else if(arr[i][j+1] == 1 && l>0){
           ans =  (ans + rec(i,j+1,l-1))%mod;
       }
    }

    return dp[i][j][l] = ans%mod;

    
}



void solve(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int l=0;l<k;l++){
               dp[i][j][l] = -1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    
    cout<<rec(0,0,k)<<endl;

}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}