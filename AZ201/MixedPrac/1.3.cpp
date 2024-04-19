#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int count =0;
    int ans =0;
    map<int,int> mp;
    int i=0;
    while(i<n){

         if(mp.find(arr[i]) == mp.end()){
            mp[arr[i]] = i;
            count++;
            ans = max(count,ans);
            i++;
         }else {

            count =0;
            i = mp[arr[i]];
            i++;
            mp.clear();
         }  
    }

    cout<<ans<<endl;

}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _;cin>>_;
    string temp;
    getline(cin,temp);
    while(_--)
    solve();

}