#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int n,s;

bool check(int x){
    int temp =x;
    int sum =0;
    while(x){
       sum += x%10;
       x =x/10;
    }
    return temp - sum >= s;
}

void solve(){
	
    cin>>n>>s;

    int lo =1;
    int hi =n;
    int ans = n+1;
    
    while(lo<= hi){
        int mid = (lo+hi)/2;

        if(check(mid)){
           ans = mid;
           hi = mid -1;
        }else {
          lo = mid+1;
        }
    }

    cout<<n - ans +1<<endl;




}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}