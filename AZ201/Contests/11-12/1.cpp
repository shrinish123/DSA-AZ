#include<bits/stdc++.h>
using namespace std;

#define int long long
int mod = 1e9+7;

int n,x,y;
int arr[1010];
int diff =0;
int dp[1010][2501];

int rec(int level,int val){
    
    if(level == n && val == diff){
        return 1;
    }else{
        return 0;
    }

    if(dp[level][val] != -1){
        return dp[level][val];
    }
    
    if(arr[level] == 1){
        

    }else{

    }
   
    


}


void solve(){
    string s ;
    cin>>s;
    cin>>n>>x>>y;

   for(int i=0;i<s.size();i++){
       if(s[i] == 'l'){
           arr[i] = -1;
       }
       else {
           arr[i] = 1;
       }
   }

    diff = y-x;

  memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)%mod<<endl;





}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}