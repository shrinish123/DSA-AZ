#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

string s1,s2;
int n,m;

int dp[2000][2000];
int bp[2000][2000];
string ans;

int rec(int l1,int l2){
    if(l1 == n || l2 == m){
        return 0;
    }
    if(dp[l1][l2] != -1){
        return dp[l1][l2];
    }
    //trans
    int ans =0;
    if(s1[l1] == s2[l2]){
       ans = 1+ rec(l1+1,l2+1);
       bp[l1][l2] = 1;
    }

    else {
        if(rec(l1+1,l2) > rec(l1,l2+1)){
            bp[l1][l2]= 2;
        }else {
            bp[l1][l2] = 3;
        }
        ans = max(rec(l1+1,l2),rec(l1,l2+1));
    }
    
    return dp[l1][l2] = ans;
    
}


void generate(int l1,int l2){
   
   if(l1 == n || l2 == m){
       return;
   }

   if(bp[l1][l2] == 1){
       ans += s1[l1];
       generate(l1+1,l2+1);
      
   }else if(bp[l1][l2] == 2){
       generate(l1+1,l2);

   }else {
       generate(l1,l2+1);
   }
}


void solve(){
   
   cin>>s1>>s2;
 n = s1.size();
 m = s2.size();
 memset(dp,-1,sizeof(dp));

  cout<<rec(0,0)<<endl;
  generate(0,0);
  cout<<ans<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}