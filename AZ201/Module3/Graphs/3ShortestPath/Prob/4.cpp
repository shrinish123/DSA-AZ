#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define ii pair<int,int>

int n,m,q;
int dis[505][505];

void solve(){
   cin>>n>>m>>q;

    for(int i=1;i<=n;i++){
       for(int j=1;j<=n;j++){
           if(i!=j){
              dis[i][j] = 1e18;
           }else{
               dis[i][j] = 0;
           }
          
       }
   }

   for(int i=0;i<m;i++){
       int a,b,c;
       cin>>a>>b>>c;
      dis[a][b] = dis[b][a]  = min( dis[a][b],c) ;
   }

  

   for(int k=1;k<=n;k++){
       for(int i=1;i<=n;i++){
           for(int j=1;j<=n;j++){
               dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
           }
       }
   }

   while(q--){
       int a,b;
       cin>>a>>b;
       if(dis[a][b] == 1e18) cout<<-1<<endl;
       else cout<<dis[a][b]<<endl;
     
   }

}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
    solve();
}