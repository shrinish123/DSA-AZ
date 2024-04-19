#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'


void solve(int t){

   int ans=0;

   int n;
   cin>>n;
   vector<int>arr(n);

   for(int i=0;i<n;i++){
    cin>>arr[i];
   }

   int pre[n+1];
   pre[0] = 0;

   for(int i=0;i<n;i++){
    pre[i+1]= pre[i] + arr[i];
   }

   for(int i=0;i<n;i++){
    int cnt =0;

    for(int j = i; j>=0;j--){
       
       if(pre[i+1] - pre[j] >= 0 ){
        cnt++;
       }
    }

    ans += cnt*arr[i];
    if(arr[i] >= 0){
        ans -= arr[i];
    }
   }

   reverse(arr.begin(),arr.end());


   int pre1[n+1];
   pre1[0] = 0;

   for(int i=0;i<n;i++){
    pre1[i+1]= pre1[i] + arr[i];
   }

   for(int i=0;i<n;i++){
    int cnt =0;

    for(int j = i; j>=0;j--){
       
       if(pre1[i+1] - pre1[j] >= 0 ){
        cnt++;
       }
    }

    ans += cnt*arr[i];
   }
   
    //ans 
    cout<<"Case #"<<t<<": "<<ans<<endl;

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    string temp;
    getline(cin,temp);
    for(int i=1;i<=t;i++){
        solve(i);
    }
}