#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define end "\n"

void solve(){
	int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
       cin>>arr[i];
    }

    int cnt[31];
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<31;i++){
        for(int j=0;j<n;j++){
            if(arr[j] & (1<<i)){
                cnt[i]++;
            }
        }
    }
    
    int ans =0;
    for(int i=0;i<n;i++){
        int largenum = 0;
      for(int j=0;j<=21;j++){
          if(cnt[j]){
          largenum = largenum | (1<<j);
          cnt[j]--;
        }
      }
      ans += largenum*largenum;
       
    }
    cout<<ans<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}