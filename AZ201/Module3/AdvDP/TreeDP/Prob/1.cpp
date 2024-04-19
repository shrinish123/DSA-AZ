#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n;
vector<vector<int>> g;
int arr[100100];
int sum[100100];
int indp[100100];
int outdp[100100];
int tot =0;

void indfs(int node,int par){
    sum[node] = arr[node];
    indp[node] = 0;

    for(auto v : g[node]){
        if(v != par){
            indfs(v,node);
            sum[node] += sum[v];
            indp[node] += indp[v] + sum[v];
        }
    }
}

void outdfs(int node,int par){
    if(node ==1){
        outdp[node] = 0;
    }else {
        outdp[node] = outdp[par] + indp[par] - indp[node] - sum[node] + tot - sum[node];
    }

    for(auto v : g[node]){
        if(v!= par){
             outdfs(v,node);
        }
      
    }
}

void solve(){
    cin>>n;
    //init
    g.clear();
    g.resize(n+1);
    
    for(int i=1;i<=n;i++){
        sum[i] =0;
        indp[i] =0;
        outdp[i] =0;
    }
    tot= 0;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        tot+= arr[i];
    }

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }


    indfs(1,0);
    outdfs(1,0);

    int maxval =0;
    int minval = 1e18;

    for(int i=1;i<=n;i++){
      maxval = max(maxval,indp[i]+outdp[i]);
      minval = min(minval,indp[i]+outdp[i]);
    }

    cout<<maxval<<" "<<minval<<endl;



}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}