#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n;
vector<int> par;
vector<int> ran;
int comp = 0;

int find(int x){
    if(x == par[x]) return x;
    else return par[x] = find(par[x]);
}

void merge(int x,int y){
  int xr = find(x); int yr =find(y);

  if(xr != yr){
      if(ran[xr] >= ran[yr]){
        par[yr] = xr;
        ran[xr] += ran[yr];
      }else {
        par[xr] = yr;
        ran[yr] += ran[xr];
      }
      comp--;
  }
}

void solve(){
  cin>>n;
  //  reset
  par.clear();
  par.resize(n+1);
  ran.clear();
  ran.resize(n+1);


  //init 

  for(int i=1;i<=n;i++){
      par[i] = i;
      ran[i] = 1;
  }
  comp = n;

  // Here comes the problem logic that you cxan implement






}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    string temp;getline(cin,temp);

    while(t--) {
        solve();
    }
   
}