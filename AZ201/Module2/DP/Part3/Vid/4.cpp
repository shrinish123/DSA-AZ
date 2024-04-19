#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"


string s;
int dp[2000];

int rec(int l){   // to return 
    if(l == 0){
        return 1;
    }

    if(dp[l] !=-1){
        return dp[l];
    }

    // 
    int ans =0;
    bool flag =0;
    for(int j = l-1;j>=0;j--){
        if(s[j] != s[l]){
             ans += rec(j);
        }
        else {
            flag =1;
            ans+= rec(j);
            break;
        }
    }
    return dp[l]= ans+(flag ? 0: 1);
}



void solve(){
   cin>>s;
   int n = s.size();
   memset(dp,-1,sizeof(dp));
   int ans =0;
   for(int i=0;i<n;i++){
     ans += rec(i);
   }
   cout<<ans<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}