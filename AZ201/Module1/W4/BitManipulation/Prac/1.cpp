#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define end "\n"

void solve(int t){

    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans =0;
    int sum = 0;
    
    for(int i =50;i>=0;i--){
        int cnt=0;
        for(int j=0;j<n;j++){
           if(arr[j] &(1LL<<i)){
               cnt++;
           }
        }
        
        
        if(sum + (n-cnt)*(1LL<<i) <=m && (sum + (n-cnt) *(1LL<<i) >=0) ){
            ans = ans | (1LL<<i);
            sum+=(n-cnt) *(1LL<<i);
        }
        else if(sum +  (cnt * (1LL<<i)) <= m  && (sum +  (cnt * (1LL<<i))>=0 )){
             sum+= cnt* (1LL<<i);
        }
        else {
            ans = -1;
            break;
        }

    }
	cout<<"Case #"<<t<<": "<<ans<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
    for(int i=1;i<=t;i++){
       solve(i);
    }
	
}