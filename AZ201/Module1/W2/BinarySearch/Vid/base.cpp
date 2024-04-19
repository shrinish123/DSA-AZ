#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

void solve(){
	
    int n ;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // binary search monotone space search herefor 0000....111

    int ans = -1,lo =0,hi = n-1;

    while(lo<=hi){

        int mid = (lo+hi)/2;

        if(arr[mid] == 1){
            hi = mid -1;
        }else {
            lo = mid+1;
            ans = mid;
        }
    }

    cout<<ans<<"\n";
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}