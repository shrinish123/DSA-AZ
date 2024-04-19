#include<bits/stdc++.h>
using namespace std;

#define int long long

bool comp(int &a ,int &b){
    return a.second > b.second;
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    map<int,int> mp;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }
   
   sort(mp.begin(),mp.end(),comp);
    

    int q;
    cin>>q;

    while(q--){
        int l,r;
        cin>>l>>r;

        int cnt = (r-l +1 )/n;

        if( l%n == 0){

        }else {
            
        }
    }
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}