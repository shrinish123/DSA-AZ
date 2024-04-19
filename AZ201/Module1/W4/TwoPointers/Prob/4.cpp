#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int freq[1001000] ={0};

void solve(){
	int n;
    cin>>n;
    int  arr[n];
    map<int,int> mp;
    for(int i=0;i<n;i++){
       cin>>arr[i];
       mp[arr[i]]++;
    }
    int k = mp.size();

    int ans = 1e18;
    int dist =0;

    int tail =0;
    int head =-1;

    while(tail < n){
        while(head+1 < n && (dist < k)){
            head++;
            freq[arr[head]]++;
            if(freq[arr[head]] == 1) dist++;
        }
        if(dist == k ) ans = min(ans,head-tail+1);

        if(tail<=head){
            freq[arr[tail]]--;
            if(freq[arr[tail]] == 0 )dist--;
            tail++;
        }else {
            tail++;
            head= tail-1;
        }
    }
    cout<<ans<<endl;

}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}