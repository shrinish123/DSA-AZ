#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'

bool ispal(int n) {
    int temp =n;
    int num = 0;
    while(n){
       num= num*10; 
       num += n%10;
       n=n/10;
    }
    return temp==num;
}

void solve(int t){

   int ans=0;
   int n;
   cin>>n;
   int i=1;
   while(i*i <= n){
       if(n%i == 0){
           if(ispal(i)){
            
             ans++;
           }

           if(n/i != i){
              if(ispal(n/i)){
            
             ans++;
           }
           }
       }
       i++;
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