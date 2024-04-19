#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

string s1,s2;
int n,m;
int dp[3001][3001];
int poin[3001][3001];

string lcs;

int rec(int l1,int l2){
   
   if(l1 == n || l2 == m) {
       return 0;
   }
   
   // 
   if(dp[l1][l2] != -1){
       return dp[l1][l2];
   }

   // 
   int ans =0;

   if(s1[l1] == s2[l2]){
       ans = 1+ rec(l1+1,l2+1);
       poin[l1][l2]= 1;
   }

   else {
       if(rec(l1+1,l2) > rec(l1,l2+1)){
           poin[l1][l2] = 2;
       }else {
              poin[l1][l2] = 3;
       }
       ans = max(rec(l1+1,l2),rec(l1,l2+1));
   }

   return dp[l1][l2] = ans;
   
}

void generate(int l1,int l2){
   if(l1 == n || l2 == m){
       return;
   }

   if(poin[l1][l2] == 1){
       lcs += s1[l1];
       generate(l1+1,l2+1);

   }else if(poin[l1][l2] == 2){
       generate(l1+1,l2);
   }else {
         generate(l1,l2+1);
   }
}

void solve(){
   cin>>s1>>s2;
   n = s1.size(); m = s2.size();
   memset(dp,-1,sizeof(dp));
   memset(poin,0,sizeof(poin));
   int length = rec(0,0);
   generate(0,0);
   cout<<lcs<<endl;


}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}