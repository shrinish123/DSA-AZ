#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"



void solve(){
   int n;
   cin>>n;
   int x[n],y[n];
   for(int i=0;i<n;i++){
       cin>>x[i]>>y[i];
   }

   sort(x,x+n);
   sort(y,y+n);

   int medx = x[n/2 ];
   int medy = y[n/2 ];
   int ans =0;
   cout<<medx<<" "<<medy<<endl;

   for(int i=0;i<n;i++){
    ans += abs(x[i] - medx);
    ans += abs(y[i] - medy);
   }

   cout<<ans<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}