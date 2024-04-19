#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n,m;
int dis[404][404];

void solve(){
   cin>>n>>m;
   
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           if(i!=j) dis[i][j] = 1e9;
       }
   }

   for(int i=0;i<m;i++){
       int a,b,c;
       cin>>a>>b>>c;

       dis[a][b]= min(dis[a][b],c);
   }

   for(int k=0;k<n;k++){
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
         }
     }
   }
   
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    string temp;getline(cin,temp);

    while(t--) 
    solve();
}