#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
int n;
int arr[200100];
vector<vector<int>> g;
int indp[200100];
int outdp[200100];

void indfs(int node ,int par){
   indp[node] = 1;

   for(auto v : g[node]){
     if(v!= par){
        indfs(v,node);

        if(arr[v] < arr[node]){
          indp[node] += indp[v];
        }
     }
   }
}

void outdfs(int node ,int par){
  if(node == 1){
    outdp[node] =0;
  }else{

    if(arr[node] > arr[par]){
      outdp[node] = outdp[par] + indp[par];
    } else{
      outdp[node] =0;
    }
  }

  for(auto v : g[node]){
    if(v!= par){
      outdfs(v,node);
    }
  }
}

void solve(int t){

   int ans =0;
   cin>>n;
   
   for(int i=1;i<=n;i++){
    cin>>arr[i];
   }

   g.clear();
   g.resize(n+1);

   for(int i=0;i<n-1;i++){
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
   }

   indfs(1,0);
   outdfs(1,0);

   for(int i=1;i<=n;i++){
    cout<<i<<" "<<indp[i]<<" "<<outdp[i]<<endl;
     ans = max(ans,indp[i]+ outdp[i]);
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