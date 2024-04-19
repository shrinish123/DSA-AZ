#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>> g;
int n,m;
int timer =0;
int lowtime[100100];
int uptime[100100];
bool Arti[100100];

void dfs(int node,int par){
    timer++;
    intime[node] = lowtime[node] = timer;
    bool isArti = false;
    int child =0;

    for(auto v : g[node]){
        if(!intime[v]){
            if(v == par){
                continue;
            }
            child++;
            dfs(v,node);

            lowtime[node] = min(lowtime[node],lowtime[v]);

            if(lowtime[v] >= intime[node]){
                isArti=true;
            }

            if(lowtime[v] > intime[node]){
                // x to v is a bridge
            }

        }else {
            lowtime[node] =min(lowtime[node],intime[v]);
        }
    }


    if( (par == 0 && child >= 2) || (par != 0 && isArti)){
       Arti[node] = true;
    }

}

void solve(){
    cin>>n>>m;
    g.resize(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}