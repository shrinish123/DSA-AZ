#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int n,q;
vector<int> arr;

bool check(int i){
    if(i == n-1) return 0;
    else return arr[i] < arr[i+1];
}

void solve(){
	

    cin>>n>>q;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int lo = 0;
    int hi =n-1;
    int peak = 0;

    while(lo <= hi ){
      
      int mid = (lo+hi)/2;

      if(check(mid)){
         lo = mid+1;

      }else {
        peak = mid;
        hi = mid -1;
      }
    }
   
    while(q--){
        int k;
        cin>>k;


        int lo =0;
        int hi = peak;
        int ans1 =-1;

        while(lo<=hi){
            int mid = (lo+hi)/2;

            if(arr[mid] <= k ){
                ans1 = mid;
                lo = mid+1;
            }else {
                hi = mid -1;
            }
        }

        lo = peak+1;
        hi = n-1;
        int ans2 =-1;

        while(lo<= hi){
            int mid = (lo+hi)/2;

            if(arr[mid] >= k){
                ans2 = mid;
                lo = mid+1;
            }else {
                hi = mid -1;
            }
        }

        if(ans1 != -1 && arr[ans1] == k ) cout<<ans1+1<<" ";
        if(ans2 != -1 && arr[ans2] == k) cout<<ans2+1;

        cout<<endl;
    }




}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}