#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'


void solve(int t){

   double ans=0;
   
   int n,m;
   cin>>n>>m;
   vector<int> arr(n);

   for(int i=0;i<n;i++){
       cin>>arr[i];
   }

   sort(arr.rbegin(),arr.rend());

   int temp =0;

   for(int i=0;i<m-1;i++){
       temp += arr[i];
   }
   
   if( (n-m+1)%2 ==0){
       int one = m-1 + (n/2) - 1;
       int two = m-1 + (n/2);
       ans = (arr[one] + arr[two])/2.0;
     
   }else {
       int one = m-1 + (n/2);
       ans = arr[one];
    
   }
   
   ans  = ans + (double)temp;




    //ans 
    cout<<"Case #"<<t<<": "<<fixed<<setprecision(6)<<ans<<endl;

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