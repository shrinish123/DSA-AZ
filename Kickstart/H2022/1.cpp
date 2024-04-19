#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define F first
#define S second


void solve(int t){

   int ans=0;

   int l,n;
   cin>>l>>n;
   vector<pair<int,int>> arr;

   for(int i=0;i<n;i++){
    int x;
    char dir;
    cin>>x>>dir;
    if(dir == 'C')arr.push_back({x,1});
    if(dir == 'A')arr.push_back({x,-1});
   }

   int len =0;

   for(int i=0;i<n;i++){
     
     len += arr[i].F*arr[i].S;

     if(len >= 0){

       if(len >= l){
            ans += len/l;
        }
        len = len%l;
     }else{

        if(abs(len) >= l){
            ans += abs(len)/l;
        }
        len = len%l;
        
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