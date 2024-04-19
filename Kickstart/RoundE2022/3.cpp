#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'

void solve(int t){
    
    int n;
    cin>>n;

    string p;
    cin>>p;

    vector<int> lps(n,0);

    for(int i=1;i<n;i++){
        int j= lps[i-1];
        while(true){
          
          if(p[i] == p[j]){
            lps[i] = j+1;
            break;
          }
          else if(j== 0){
            lps[i] =0;
            break;
          }
          else{
            j = lps[j-1];
          }
        } 
    }

    int ans = n - lps[n-1];
   
   string q;

   if(n % ans !=0){
      q = p;
      
   }else {
      q = p.substr(0,ans);
   }

   
   
  
   cout<<"Case #"<<t<<": "<< q<<endl;
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