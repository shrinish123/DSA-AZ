#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int n;
int arr[100100];
string s[100100];
string rev[100100];
int dp[100100][2];

int rec(int l,int j){
   if(l== n ){
       return 0;
   }

   if(dp[l][j] != -1){
       return dp[l][j];
   }
   int ans =1e18;
   if(j) {
    if(rev[l -1]  <= s[l]){
        ans = min(ans, rec(l+1,0));
    }
    if(rev[l-1] <= rev[l]){
        ans = min(ans,arr[l]+rec(l+1,1));
    }
   }
   else {
       if(s[l-1] <= s[l]){
           ans = min(ans,rec(l+1,0));
       }
       if(s[l-1] <= rev[l]){
           ans = min(ans,arr[l]+rec(l+1,1));
       }
   }

   return dp[l][j] =ans;
}

void solve(){
  cin>>n;
  for(int i=0;i<n;i++){
      cin>>arr[i];
  }
  for(int i=0;i<n;i++){
      string str;
      cin>>str;
      s[i] = str;
     reverse(str.begin(),str.end());
     rev[i] = str;
  }

  for(int i=0;i<n;i++){
      for(int j=0;j<2;j++){
          dp[i][j] = -1;
      }
  }

  
   int ans = min(rec(1,0),rec(1,1));
   if(ans != 1e18){
       cout<<ans <<endl;
   }else {
      cout<<-1<<endl;
   }
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}