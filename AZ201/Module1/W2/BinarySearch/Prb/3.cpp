#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int n,k;
vector<int> arr;

bool check(int x){
    int cnt =0;
    for(int i=1;i<n;i++){
        int dif = arr[i] - arr[i-1];
        if(dif % x == 0){
            cnt += (dif/x) -1; 
        }else {
            cnt += (dif/x);
        }
    }

    if(cnt <= k ){
        return 1;
    }else {
        return 0;
    }
}

void solve(){
	cin>>n>>k;
    arr.resize(n);
    int maxdiff =0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i){
            maxdiff = max(maxdiff, arr[i] - arr[i-1]);
        }
    }

    int lo = 1;
    int hi = maxdiff;
    int ans = 1;

    while(lo<=hi){

        int mid = (lo+hi)/2;

        if(check(mid)){
          ans = mid;
          hi =mid -1;
        }else {
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