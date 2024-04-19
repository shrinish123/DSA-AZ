#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int n,k;
int a[1001000];

bool check(int x){
    int cnt =1;
    int prev =a[0];
    for(int i=1;i<n;i++){
      if(a[i] >= prev + x ){
         cnt++;
         prev = a[i];
      }
    }
    return cnt >= k;
}

void solve(){
	cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);

    int lo = 1;
    int hi = a[n-1] - a[0];

    int ans= 1;

    while(lo <= hi){

        int mid = (lo+hi)/2;

        if(check(mid)){
           ans = mid;
           lo =mid +1;
        }else {
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