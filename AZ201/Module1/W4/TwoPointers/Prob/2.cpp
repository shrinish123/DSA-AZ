#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

void solve(){
	int n,k;
    cin>>n>>k;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int sum =0;

    int ans =0;

    int tail =0;
    int head =-1;

    while(tail< n){
        while(head+1< n && sum + arr[head+1] <= k){
            head++;
            sum += arr[head];
        }

        ans += (head-tail+1);

        if(tail<=head){
            sum = sum -arr[tail];
            tail++;
        }else {
            tail++;
            head =tail-1;
        }
    }

    cout<<ans<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}