#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

vector<vector<int>> g;
vector<int> col;

int n,m;
bool iscyc = 0;

void dfs(int node) {
    col[node] = 2;

    for(auto v : g[node]){
        if(col[v] == 1){
            dfs(v);
        }
        else if(col[v]== 2){
             iscyc =1;
        }
    }

    col[node] =3;
}

void solve(){
 cin>>n>>m;

 g.clear();
 g.resize(n+1);
 col.assign(n+1,1);

 for(int i=0;i<m;i++){
     int a,b;
     cin>>a>>b;
     g[a].push_back(b);
 }

 for(int i=1;i<=n;i++){
     if(col[i] == 1){
         dfs(i);
     }
 }

 if(iscyc) cout<<"Yes"<<endl;
 else cout<<"No"<<endl;
 iscyc=0;

}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    string temp;getline(cin,temp);

    while(t--) 
    solve();
}

// https://www.learning.algozenith.com/problems/Round-Trip-II-880