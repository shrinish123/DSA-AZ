#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F first
#define S second

int n,m,q;
int comp =0;
vector<vector<int>> g;
vector<int> par;
vector<int> ran;

int find(int x){
    if( par[x] == x) return x;
    else return par[x] = find(par[x]);
}

void merge(int x,int y){
    int xr = find(x); int yr = find(y);

    if(xr != yr){
        if(ran[xr] >= ran[yr]){
            par[yr] = xr;
            ran[xr] += ran[yr];
            ran[yr] = 1;
        }else {
              par[xr] = yr;
            ran[yr] += ran[xr];
            ran[xr] = 1;
        }
        comp--;
    }
}

void solve(){
  cin>>n>>m>>q;
  g.clear();
  g.resize(n+1);
  par.clear();
  par.resize(n+1);
  ran.clear();
  ran.assign(n+1,1);

  for(int i=0;i<n;i++){
      par[i] = i;
  }
  comp =n;

 map<int,pair<int,int>> edgelist;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
     edgelist[i+1] = {a,b};
  }

  vector<int>edgenum;
  vector<pair<int,int>> Q;
  int tempq = q;
   while(q--){
       int t;
       cin>>t;
       if(t== 1){
           int x;
           cin>>x;
        edgenum.push_back(x);
        Q.push_back({1,x});
       }
       else {
           Q.push_back({2,0});
       }
   }

   vector<bool> checkedge;
   checkedge.assign(m+1,false);
  
   for(auto v : edgenum){
       checkedge[v] = true;
     
   }

   vector<int> remedge;

   for(int i=1;i<=m;i++){
       if(!checkedge[i]) remedge.push_back(i);
   }
   
   for(auto v : remedge){
       int x =edgelist[v].F;
       int y  = edgelist[v].S;
     
       merge(x,y);
   }
   //////////
   bool isfirst = 1;
   q = tempq;
   for(int i=q-1;i>=0;i--){
    
       if(Q[i].F == 1 && isfirst){
            int edgen = Q[i].S;
           Q[i].S = comp;
          
           int x = edgelist[edgen].F;
           int y = edgelist[edgen].S;
           merge(x,y);
           isfirst=0;
       }
       else if(Q[i].F == 1 && !isfirst){
           int edgen = Q[i].S;
           Q[i].S = comp;
           
           int x = edgelist[edgen].F;
           int y = edgelist[edgen].S;
           merge(x,y);
       }
   }
   int val = comp;
   for(int i=0;i<q;i++){
     if(Q[i].F == 1){
        val = Q[i].S;
     }
     else if(Q[i].F == 2){
         Q[i].S = val;
     }
   }

   for(int i=0;i<q;i++){
     
       if(Q[i].F == 2){
           cout<<Q[i].S<<endl;
       }
   }



}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
        solve();
    
   
}