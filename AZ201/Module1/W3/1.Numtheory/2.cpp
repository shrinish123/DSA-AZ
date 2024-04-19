#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    
    int n;
    cin>>n;
    int ans = n;
    vector<pair<int,int>> fac;

    for(int i=2;i*i<=n;i++){
        if(n%i ==0){
            int cnt =0;
            while(n%i == 0){
                cnt++;
                n/= i;
            }
            fac.push_back({i,cnt});
        }
    }
    if(n>1) fac.push_back({n,1});
  

    for(auto v : fac){
      ans = ans/v.first;
      ans = ans * (v.first -1);
    }

    cout<<ans<<endl;
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int _t;cin>>_t;while(_t--)
    solve();
}