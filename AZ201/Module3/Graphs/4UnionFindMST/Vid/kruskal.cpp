#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F first
#define S second

int n,m;
int comp =0;
vector<int> rankuf;
vector<int> par;

int find(int x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}

void merge(int x,int y){
    int xr = find(x);int yr  = find(y);

    if( xr != yr){
        if(rankuf[xr]>= rankuf[yr]){
            par[yr] = xr;
            rankuf[xr]+= rankuf[yr];
        }
        else {
             par[xr] = yr;
            rankuf[yr]+= rankuf[xr];
        }
        comp--;
    }
}


void solve(){
  // reset
  cin>>n>>m;
  rankuf.clear();
  rankuf.resize(n+1);
  par.clear();
  par.resize(n+1);

  //init
  for(int i=1;i<=n ;i++){
      par[i] = i;
      rankuf[i] = 1; 
  }
  comp =n;

  // kruskal 

  vector<pair<int,pair<int,int>>> ed;

  for(int i=0;i<m;i++){
      int a,b,c;
      cin>>a>>b>>c;
      ed.push_back({c,{a,b}});
  }

  sort(ed.begin(),ed.end());
  int ans = 0;

  for(auto v : ed){
      int x = v.S.F;
      int y = v.S.S;
      int wt = v.F;


      if(find(x) != find(y)){
         ans+= wt;
         merge(x,y);
      }
  }
  cout<<ans<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
        solve();
    
   
}