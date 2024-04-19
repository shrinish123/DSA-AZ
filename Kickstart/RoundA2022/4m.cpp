#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'


void solve(int t){

   int ans;
   int a,b;
   cin>>a>>b;
   int count =0;
   for(int i=a;i<=b;i++){
       int num = i;
       int sum = 0;
       int prod =1;
       while(num> 0){
           int test = num%10;
           sum += test;
           prod *= test;
           num = num/10;
       }
       if(prod%sum ==0 ){count++;}
   }
    ans =count;

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