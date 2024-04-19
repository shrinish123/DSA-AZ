#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"



void solve(){
   int n;
   cin>>n;
   int a[n];
   int b[n];
   for(int i=0;i<n;i++){
	   cin>>a[i];
   }
    for(int i=0;i<n;i++){
	   cin>>b[i];
   }
   sort(a,a+n);
   sort(b,b+n);

   int ans =0;

   for(int i=0;i<n;i++){
      ans += abs(a[i]-b[i]);
   }
   cout<<ans<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}