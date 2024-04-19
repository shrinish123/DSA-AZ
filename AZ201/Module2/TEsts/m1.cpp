#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }

    sort(arr,arr+n);

    int ans =0;

    for(int i=0;i<n;i++){

        if(i){
              ans  += min( abs(arr[i]-arr[i-1]), abs(arr[i+1] - arr[i]));
        }
        else {
            ans += arr[i+1] - arr[i];
        }
    }
    cout<<ans<<endl;
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int _t;cin>>_t;while(_t--)
    solve();
}