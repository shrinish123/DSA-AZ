#include<bits/stdc++.h>
using namespace std;

#define int long long



void solve(){
    int n,m;
    cin>>n>>m;
    
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x]++;
    }
    vector<pair<int,int>> vmp;
    for(auto v : mp){
        vmp.push_back({v.second,v.first});
    }
   
    sort(vmp.begin(),vmp.end());
    int sz = vmp.size();
    int ans =0;
    for(auto v : vmp){

        if(m >= v.first){
            m = m - v.first;
            ans++;
        }
    }

    cout<< sz - ans<<endl;;

}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int _t;cin>>_t;while(_t--)
    solve();
}