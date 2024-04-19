#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define end "\n"

void solve(){
	int n,x;
    cin>>n>>x;

    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans =0;
    for(int i=30;i>=0;i--){
        vector<int> bitele;

        for(auto v : arr){
            if(v & (1<<i)){
                bitele.push_back(v);
            }
        }

        if(bitele.size() >= x ){
            ans = ans | (1<<i);
            arr = bitele;
        }
    }

    cout<<ans<<endl;

}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}