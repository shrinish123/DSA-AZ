#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
int n,q;
vector<vector<int>> g;
int level[65536];
int cnt[65536];
int levcnt[65536];


void solve(int t){

   int ans=0;
   
   cin>>n>>q;
   
   g.clear();
   g.resize(n+1);
   
   for(int i=0;i<n-1;i++){
      int a,b ;
      cin>>a>>b;
      g[a].push_back(b);
      g[b].push_back(a);
   }

   for(int i=1;i<=n;i++){
      level[i] = 1e9;
   }
  
   queue<int> qu;
   qu.push(1);
   level[1] = 1;
   

   while(!qu.empty()){

      int cur = qu.front();
      qu.pop();
      
      for(auto v : g[cur]){

         if(level[v] > level[cur] +1){
            level[v] = level[cur] +1;
            qu.push(v);
         }
      }
   }

   for(int i=1;i<=n;i++){
      levcnt[i] =0;
      cnt[i] = 0;
   }
   int depth =0;
   for(int i=1;i<=n;i++){
       levcnt[level[i]]++;
       depth = max(depth,level[i]);
   }

   for(int i=0;i<q;i++){
      int cont;
      cin>>cont;
      
      int curlevel = level[cont];
      bool mark = 0;
      for(int i=1;i<=curlevel;i++){

         if(cnt[i] < levcnt[i]){
             cnt[i]++;
             mark =1;
             break;
         }
      }

      if(!mark){

         for(int i=curlevel+1;i<=depth;i++){
            if(cnt[i] < levcnt[i]){
             cnt[i]++;
             break;
         }

         }
      }
   }

   for(int i=1;i<=depth;i++){

      if(cnt[i] == levcnt[i]){
         ans += levcnt[i];
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