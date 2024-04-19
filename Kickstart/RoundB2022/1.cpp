#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'


void solve(int t){

   int ans=0;
   
   int r,a,b;
   cin>>r>>a>>b;
   int radius = r;
   int i=0;

   while(radius){
       ans += radius*radius;

       if(i%2==0) radius = radius * a;
       else  radius= radius /b;
       i++;
      
   }
    double pi = 2 * acos(0.0);

    //ans 
    cout<<"Case #"<<t<<": ";
    cout<<fixed<<setprecision(6)<<ans*pi<<endl;

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