#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
#define N 1000005

int n,m,k;
int a[N],b[N];


bool check(int x){
    int cnt =0;
    for(int i=0;i<n;i++){
       int temp =  upper_bound(b,b+m,x-a[i]) - b ;
       cnt += temp;
    }

    return cnt >= k;
}


void solve(){
	cin>>n>>m>>k;
   

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
       cin>>b[i];
    }
     if(n > m) {
            swap(a, b);
            swap(n, m);
        }
  

    sort(a,a+n);
    sort(b,b+m);


    int lo = a[0] + b[0];
    int hi = a[n-1]+b[m-1];
    int ans = a[0] + b[0];

    while(lo <= hi){

        int mid = (lo+hi)/2;
       
        if(check(mid)){
            ans = mid;
          
            hi = mid -1;
        }else {
             lo = mid+1;
        }
    }

    cout<<ans<<endl;

    

}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}