#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int n,k,d;
 map<int,int> mp;

bool check(int x ){
    int cnt =0;

    for (auto v :mp ){
        cnt += min(x, v.second);
    }

    return cnt >= x * k;
}

void solve(){
	cin>>n>>k;
    
    for(int i=0;i<n;i++){
        int x;cin>>x;
        mp[x]++;
    }

    int cnt =0;
    int lo =0;
    int hi = n;
    int ans =0;
    
    while(lo<= hi ){
        int mid = (lo+hi)/2;

        if(check(mid)){
           ans = mid;
           lo =mid+1;
        }else {
           hi = mid -1;
        }
    }

    cout<< ans<<endl;
    mp.clear();

}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}