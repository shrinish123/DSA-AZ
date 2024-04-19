#include<bits/stdc++.h>
using namespace std;

#define int long long

bool comp(pair<int,int> &x ,pair<int,int> &y ){
    return x.second < y.second;
}

void solve(){
    int n;
    cin>>n;

     vector<pair<int,int>> a;
    
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a.push_back({x,y});
    }
    
    sort(a.begin(),a.end(),comp);

    for(int i=0;i<n;i++){
        cout<<a[i].first<<" "<<a[i].second<<endl;
    }
    
    int ans =1;
    int prev = a[0].second;
    
    for(int i=0;i<n;i++){
        
        if(a[i].first > prev){
            ans++;
            prev = a[i].second;
        }
    }
    cout<<ans<<endl;
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int _t;cin>>_t;while(_t--)
    solve();
}