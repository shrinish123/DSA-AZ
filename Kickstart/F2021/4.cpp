#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'

int n,m,k;
int l[16],r[16],a[16];
vector<vector<int>> g;
int count =0;
int points =0;

void dfs(int node){
    if(points == k ){
        count++;
    }
    vis[node] = 1;

    for(auto v : g[node]){


    }
}

void solve(int t){

   int ans=0;
   cin>>n>>m>>k;
  for(int i=0;i<n;i++){
    cin>>l[i]>>r[i]>>a[i];
  }
  g.clear();
  g.resize(n);


  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> vis(n,0);

  for(int i=0;i<n;i++){
    points=a[i];
    vis.assign(n,0);
    count =0;
    if(points >= l[i] && points <= r[i]){
       dfs(i);
    } 
    ans += count;
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