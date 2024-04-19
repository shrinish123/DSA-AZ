#include<bits/stdc++.h>
using namespace std;

#define int long long

bool comp(pair<int,int> &a,pair<int,int> &b){
    return a.first - a.second > b.first - b.second;
}

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> sol;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        sol.push_back({a,b});
    }

    sort(sol.begin(),sol.end(),comp);

    int ans =0;
    int need = sol[0].first;

    for(int i=0;i<n-1;i++){
      ans +=need;
      int left = sol[i].first - sol[i].second;
      need = sol[i+1].first - left;
    }
    ans += need;
    cout<<ans<<endl;
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}