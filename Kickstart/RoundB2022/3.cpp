#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'


void solve(int t){

   int ans=1;
   
  int n,d;
  cin>>n>>d;
  int arr[n];
  for(int i=0;i<n;i++){
      cin>>arr[i];
      
  }

  for(int i=1;i<n;i++){
       if(arr[i] != arr[i-1] && arr[i] !=0){
            ans++;
       }
  }

  if(arr[0] == 0)ans--;

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