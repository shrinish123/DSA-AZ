#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define end "\n"

void solve(){
	 int n;
     cin>>n;
     vector<int> arr(n,0);

     for(int i=0;i<n;i++){
         cin>>arr[i];
     }

     for(int m = 0;m<=((1LL<<n)-1);m++){
          cout<<"{ ";
         for(int i=0;i<n;i++){
             if(m & (1LL<<i)){
                 cout<<arr[i]<<" ";
             }
         }
         cout<<"}"<<endl;
     }
     
     //generating submasks 

      int sum =0;
     for(int m = 0;m<=((1LL<<n)-1);m++){
         
         for(int sm = m ;sm ;sm = (sm-1) & m ){
             for(int i=0;i<n;i++){
                 if(sm & (1LL<<i))
                 sum+=arr[i];
             }
         }
     }

     cout<<sum<<endl;


}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}