#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define double long double 
#define endl "\n"

int n;
double arr[3001];
double dp[3001][3001];
bool saved[3001][3001];

double rec(int level,int heads){
 if(level == n ){
     if(heads == 0){
         return 1;
     }else {
         return 0;
     }
 }

 if(saved[level][heads]){
     return dp[level][heads];
 }

 double ans = (1-arr[level]) * rec(level+1,heads);  

 if(heads > 0){
     ans += arr[level] * rec(level+1,heads-1);
 }
  
   saved[level][heads] = 1;
 return dp[level][heads] =ans;
}

void solve(){
   cin>>n;
   
   for(int i=0;i<n;i++){
      cin>>arr[i];
   }
 

   double ans =0;

//    memset(dp,-1,sizeof(dp));
 /// DONT USE MEMSET ON A DOUBLE ARRAY
   memset(saved,0,sizeof(saved));
   
   for(int i=(n/2)+1;i<=n;i++){
      
       ans += rec(0,i);
   }

   cout<<fixed<<setprecision(10)<<ans<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}

