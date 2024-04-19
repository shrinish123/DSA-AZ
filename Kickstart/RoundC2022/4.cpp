#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'


void solve(int t){

   
   int n;
   cin>>n;
   string s;
   cin>>s;
   bool a=0,b=0,c=0,d=0,e=0;
   if(n >= 7) a =1;

   for(int i=0;i<n;i++){
      if(s[i] >= 'a' && s[i] <= 'z'){
          c=1;
      }
      if(s[i] >= 'A' && s[i] <= 'Z' ){
          b =1;
      }
      
       if(s[i] >= '0' && s[i] <= '9' ){
          d =1;
      }

      if( s[i] == '#' || s[i] == '@' || s[i] == '*' || s[i] == '&'){
          e =1;
      }

   }

   if(!b) {
       s+= 'A';
   }
   if(!c) {
       s+= 'a';
   }
   if(!d){
       s+= '0';
   }
   if(!e){
       s+='@';
   }

   if(s.size() < 7){
       int temp= 7 -(int)s.size();
       for(int i=0;i<temp;i++){
           s+= 'a';
       }
   }




    //ans 
    cout<<"Case #"<<t<<": "<<s<<endl;

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