#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"



void solve(){
    int x,y;
    cin>>x>>y;
    int ans =0;

    while(y>x ){
       if(y%2 ){
           y++;
           ans++;
       }
       y =y/2;
       ans++;
    }
    ans += (x-y);
    cout<<ans<<endl;
   
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}