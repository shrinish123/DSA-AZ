#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    
    int n;
    cin>>n;
    vector<int> ratings(n+2);
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>ratings[i];
        v.push_back({ratings[i],i});
    }

    sort(v.begin(),v.end());

    vector<int> min(n,0);




}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}