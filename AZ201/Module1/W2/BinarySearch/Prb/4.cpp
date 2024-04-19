#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int n,k;
vector<int> arr;
vector<int> pre;

bool check(int x){
    for(int i=0;i<n-x+1;i++){
        int ones =0;
        if(i){
              ones = pre[i+x-1] - pre[i-1];
        }else {
             ones = pre[i+x-1] - 0;
        }
        int ze = x - ones;
        if(ze <= k) return 1;
    }
    return 0;

}

void solve(){
	cin>>n>>k;
    arr.resize(n);
    pre.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        pre[i] = arr[i];
        if(i) pre[i] += pre[i-1];
    }

    int lo = 0;
    int hi = n;

    int ans = 0;

    while(lo <= hi){
       
       int mid= (lo+hi)/2;

       if(check(mid)){
         ans = mid;
         lo =mid +1;
       }
       else {
            hi = mid -1;
       }
    }
    cout<<ans<<endl;

}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}