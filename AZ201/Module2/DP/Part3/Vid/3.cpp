#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int n;
int dp[2000][2][2][2];
int dp2[2000][4];

int betterrec(int l,int s){
   if(l ==n){
       return 1;
   }

   if(dp2[l][s] != -1){
     return dp2[l][s] ;
   }
   int ans =0;
   
   if(s ==0){
      ans  = betterrec(l+1,1)+ betterrec(l+1,0);
   }else if(s ==1){
     ans =  betterrec(l+1,1)+ betterrec(l+1,2);
   }else if(s ==2){
    ans = betterrec(l+1,3) + betterrec(l+1,0);
   }else {
    ans  = betterrec(l+1,2);
   }

   return dp2[l][s] = ans;
}

int rec(int l,int f,int s ,int t){
    if(l == n){
        return 1;
    }
    
    if( f != -1 && s!= -1 && t!= -1 && dp[l][f][s][t] != -1){
        return dp[l][f][s][t];
    }

    int ans =0;

    ans += rec(l+1,s,t,1);

    if(f == 0 && s ==1 && t ==0){
      //do nothing 
    }else {
        ans += rec(l+1,s,t,0);
    }

    return dp[l][f][s][t] = ans;
}

void solve(){
  cin>>n;
  memset(dp,-1,sizeof(dp));
    memset(dp2,-1,sizeof(dp2));
  cout<<rec(0,-1,-1,-1)<<endl;
  cout<<betterrec(0,0)<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}