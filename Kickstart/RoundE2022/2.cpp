#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define ii pair<int,int>
#define F first
#define S second

void solve(int t){

   int n;
   cin>>n;
   vector<ii> arr(n);

   for(int i=0;i<n;i++){
    int x;
    cin>>x;
    arr[i] = {x, i};
   }

   sort(arr.begin(),arr.end());
   vector<int> ans(n);

   int j=0;

   for(int i=0;i<n;i++){
     
     while( arr[j+1].F <= (2*arr[i].F) && (j+1 <= n-1) ){
        j++;
     }

     if( i!= j){
           
        ans[arr[i].S] = arr[j].F;
     }
     else if( i==j && j != 0){
          
          ans[arr[i].S]  = arr[j-1].F;
     }
     else if( i== j && j== 0){
        ans[arr[i].S] = -1;
     }
   }
  
   cout<<"Case #"<<t<<": ";
   for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
   }
   cout<<endl;

   
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
      solve(i);
    }
}