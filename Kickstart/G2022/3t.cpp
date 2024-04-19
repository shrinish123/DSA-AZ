#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'


void solve(int t){

   int ans=0;

   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
      cin>>arr[i];
   }
   int pref[n];

   pref[0] = arr[0];

   for(int i=1;i<n;i++){
    pref[i] = pref[i-1]+ arr[i];
   }



   for(int i=0;i<n;i++){

    if(arr[i] < 0 ) continue;
    
    for(int j=i;j<n;j++){
    
      int pre[n];
      
    

      for(int k=i;k<=j;k++){
        if(k==i){
            pre[k] = arr[i];
        }else{
            pre[k] = pre[k-1] + arr[k];
        }
      }
       bool flag = 0;

      for(int k=i;k<=j;k++){
        if(pre[k] < 0){
            flag =1;
            break;
        }
      }

      if(flag == 0){
        ans += pref[j] - ( i == 0 ? 0 : pref[i-1]);
      }

    }
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