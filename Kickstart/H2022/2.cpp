#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'


void solve(int t){

   int ans=0;
   int n;
   cin>>n;
   
    if(n <= 13){
        ans =n;
    }else{

        if(n == 14)ans =13;
        if(n == 15)ans =13;
        if(n == 16)ans = 14;
        if(n == 17) ans = 15;
        if(n==18)ans = 14;
        if(n==19)ans = 15;
        if(n== 20) ans = 15;
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