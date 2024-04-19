#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,k;
int arr[300100];

bool check(int mid){

    int cnt =0;

    for(int i=0;i<n;i++){
        
        if(i){
            int diff = arr[i] - arr[i-1];

           if(diff > mid){
               cnt++;
           }
        }
    }

    if(cnt <= k) return true;
    return false;
}

void solve(){
 
    cin>>n>>k;

    
    int lo =1e18;
    int hi = 0;

    for(int i=0;i<n;i++){
       cin>>arr[i];

       if(i){
           lo = min(lo,arr[i]-arr[i-1]);
          hi = max(hi,arr[i] - arr[i-1]); 
       }
    }

    int ans =hi;

    while(lo <= hi){

        int mid = (lo+hi)/2;

        if(check(mid)){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid +1;
        }
    }

    cout<<ans<<endl;
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}