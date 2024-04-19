#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'

int n,m;

int dp[2510][2510];

int word[2510];
int key[2510];
map<int,vector<int>> mp;

int rec(int level,int ind){
    if(level == n-1){
        return 0;
    }

    if(dp[level][ind] != -1){
        return dp[level][ind];
    }
     

     int ans =1e18;

     int nex = word[level+1];
        

     for(int i=0;i< mp[nex].size();i++){

         ans = min(ans, abs(ind - mp[nex][i]) + rec(level+1,mp[nex][i]));
     }
      
     return dp[level][ind] = ans; 
}


void solve(int t){

   int ans=1e18;
   

   cin>>n;

  
   for(int i=0;i<n;i++){
       cin>>word[i];
   }

   
   cin>>m;

   for(int i=0;i<m;i++){
       cin>>key[i];
       mp[key[i]].push_back(i);
   }

   memset(dp,-1,sizeof(dp));

   for(int i=0;i<m;i++){
       if(key[i] == word[0]){
           ans = min(ans,rec(0,i));
       }
   }

   


    //ans 
    cout<<"Case #"<<t<<": "<<ans<<endl;

    mp.clear();

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