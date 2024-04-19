#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

vector<int> ran;
vector<int> par;
int n,q;
int comp =0;

int find(int x) {
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}

void merge(int x,int y) {
    int xr = find(x);int yr =find(y);

    if(xr != yr){
        if(ran[xr] >= ran[yr]){
            par[yr] = xr;
            ran[xr]+= ran[yr];
            ran[yr] = 0;
        }else {
             par[xr] = yr;
            ran[yr]+= ran[xr];
            ran[xr] =0;
        }
        comp--;
    }
}

void solve(){
  cin>>n>>q;
  ran.clear();
  ran.assign(n,1);
  par.clear();
  par.resize(n);

  for(int i=0;i<n;i++){
      par[i] = i;
  }
  comp = n;


  while(q--){
      int t,x,y;
      cin>>t>>x>>y;
       if(t == 0){
          merge(x,y);

       }else {
          if(find(x) == find(y)){
              cout<<1<<endl;
          }else cout<<0<<endl;
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