#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'


void solve(int t){

   int ans;
   int flag = 0;
   string in,p,test,testp;
   cin>>in>>p;
   test = in;
   testp = p;
    ans = p.size() - in.size();

   for(int i=0;i<p.length();i++){
       size_t found = in.find(p[i]);
        if (found != string::npos){
           in.erase(in.begin()+found);
        }
   }
   
   if(in.size() > 0){
        flag =1;
   }else {
       for(int i=0;i<test.length();i++){
         size_t found = p.find(test[i]);
        if (found != string::npos){
           p.erase(p.begin()+found);
        }
       }
     
       for(int i=0;i<p.length();i++){
          size_t found = testp.find(p[i]);
        if (found != string::npos){
           testp.erase(testp.begin()+found);
        }
       }
      
       if(testp != test){
           flag =1;
       } 
       

   }
   
    //ans 
    if(flag){
         cout<<"Case #"<<t<<": "<<"IMPOSSIBLE"<<endl;
    }else {
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
   

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