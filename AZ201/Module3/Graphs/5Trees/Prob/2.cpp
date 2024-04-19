#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n;
int D;
vector<vector<int>> g;
vector<int> dep;
vector<int> par;

vector<int> leafs;



void dfs(int node,int parent,int depth){
    dep[node] = depth;
    par[node] = parent;

    for(auto v : g[node]){
        if(v != parent){
           dfs(v,node,depth+1);
        }
    }
}

void solve(){
   cin>>n;
   g.resize(n+1);
   dep.resize(n+1);
   par.resize(n+1);

   for(int i=0;i<n-1;i++){
       int a,b;
       cin>>a>>b;
       g[a].push_back(b);
       g[b].push_back(a);
   }
   // find dimaeter
   dfs(1,0,0);
   int maxval =0;
   int y =0;

   for(int i=1;i<=n;i++){
       if(dep[i] > maxval){
         y = i;
         maxval = dep[i];
       }
   }

   dfs(y,0,0);

  maxval =0;
  int z = 0;
  for(int i=1;i<=n;i++){
       if(dep[i] > maxval){
         maxval = dep[i];
         z = i;
       }
   }

   D = maxval;
   
   int ans = 0;
   // find center/s  and find dimateres
    

   if(D%2 == 0){
    // 1 cen case
    int j =D/2;
    int temp =z;
    while(j--){
      temp = par[temp];
    }
    int center = temp;

    for(auto v : g[center]){
       dep.clear();
       dep.assign(n+1,1e9);
      
         int cnt =0;
         dfs(v,center,0);
         for(int i=1;i<=n;i++){
             if(dep[i] == (D/2) - 1) cnt++;
         }
         leafs.push_back(cnt);
    }

   

    int sum= 0;

    for(auto v : leafs){
        sum+= v;
    }

    for(auto v : leafs){
        ans += v *(sum - v);
    }
    ans = ans/2;


   }else {

      ///2 center case 

    int center1 = 0;
    int center2 = 0;
      
     int j =D/2;
     int temp =z;
     
     while(j--){
      temp = par[temp];
     }

    center1 = temp;
    center2 = par[temp];
    

    dep.clear();
    dep.assign(n+1,1e9);
  

    dfs(center1,center2,0);
    int cnt1 =0;
  
    for(int i=1;i<=n ;i++){
        if(dep[i] == D/2)cnt1++;
    }
  

    dep.clear();
    dep.assign(n+1,1e9);
   

    dfs(center2,center1,0);
    int cnt2 =0;
    for(int i=1;i<=n ;i++){
        if(dep[i] == D/2)cnt2++;
    }

    ans = cnt1 * cnt2;
   }

   if(n==1 || n==2)cout<<1<<endl;
   else cout<<ans<<endl;
   
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
        solve();
    
   
}