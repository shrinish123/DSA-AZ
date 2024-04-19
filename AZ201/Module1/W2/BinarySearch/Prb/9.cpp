#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int n,k;
int arr[1001000];

bool check(int x ){

    int tail =0;
    int head =-1;
    int ans =0;
    int sum =0;

    while(tail < n ){
        while(head+1 < n  && (sum +arr[head+1] <= x )){
            head++;
            sum+= arr[head];
        }

        ans += (head- tail+1);

        if(tail<= head){
            sum -= arr[tail];
            tail++;
        }else {
            tail++;
            head =tail-1;
        }
    }

    return ans >= k ;
}

void solve(){
	cin>>n;
    int sm=1e18;
    int sum =0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sm = min(sm,arr[i]);
        sum += arr[i];
    }

    int l = (n)*(n+1)/2;

    if(l%2){
        k = (l/2) +1;
    }else {
        k = l/2;
    }

    int lo = sm ;
    int hi = sum;
    int ans = sum;

    while(lo<=hi){
       
       int mid = (lo+hi)/2;

       if(check(mid)){
           ans= mid;
           hi = mid -1;
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