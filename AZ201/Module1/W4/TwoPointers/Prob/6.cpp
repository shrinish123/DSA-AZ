#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

void solve(){
	int n,t;
    cin>>n>>t;
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans =1e18;

    for(int j=0;j<n;j++){
        int i=0;
        int k =n-1;
        
        while(i<j && j< k){
            int sum = arr[i]+ arr[j] + arr[k];
            if(sum == t) {
                ans = 0;
                break;
            }
            else if( sum < t){
              if(abs(sum -t) < ans){
                  ans = abs(sum -t);
              }
              i++;
            }
            else {
                if(abs(sum -t) < ans){
                  ans = abs(sum -t);
              }
             k--;
            }
        }

    }
    cout<<ans<<endl;


}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}