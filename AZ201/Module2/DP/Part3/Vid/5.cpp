#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"



void solve(){
   string s ;
   cin>>s;
   int n = s.size();
   int last[26];
   memset(last,-1,sizeof(last));
   int sum[n];
   sum[0] =1;
   last[s[0]-'a'] = 1;
   for(int i=1;i<n;i++){
     int flag =0;
     if(last[s[i]-'a'] == -1){
        flag =1;
     }
     last[s[i]-'a'] = i;
     sum [i] = flag + sum[i-1];
   }
    int ans =0;
   for(int i=0;i<n;i++){
    ans += sum[i];
   }
   cout<<ans<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}

//distinct nmber of substrings 