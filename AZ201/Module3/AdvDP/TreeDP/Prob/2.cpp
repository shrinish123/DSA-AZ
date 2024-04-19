#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F first
#define S second

int n;
vector<vector<pair<int,int>>> g;
int indp[100100];
int outdp[100100];

void indfs(int node,int par){
    indp[node] = 0;

    for(auto v : g[node]){
        if(v.F != par){
            indfs(v.F,node);
            indp[node] += indp[v.F] + v.S;
        }
    }
}

void outdfs(int node,int par,int wei){
    if(node ==1){
        outdp[node] =0;
    }else {
        outdp[node] = outdp[par] + indp[par] - (indp[node] + wei) + (!wei);
    }

    for(auto v : g[node]){
        if(v.F!= par){
            outdfs(v.F,node,v.S);
        }
       
    }
}


void solve(){
    cin>>n;
   
    g.clear();
    g.resize(n+1);

    for(int i=1;i<=n ;i++){
        indp[i] = 0;
        outdp[i] =0;
    }

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back({b,0});
        g[b].push_back({a,1});
       
    }

    indfs(1,0);
    outdfs(1,0,0);

    int mini =1e18;

    for(int i=1;i<=n;i++){
      
         mini = min(mini,indp[i]+outdp[i]);
    }

    cout<<mini<<endl;


    for(int i=1;i<=n;i++){
        if(indp[i] + outdp[i] == mini){
            cout<<i<<" ";
        }
    }
    cout<<endl;
   
    
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}