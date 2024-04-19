#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

vector<vector<int>> g;
vector<int> col;
vector<int> cycle;

vector<int> parent;

void dfs(int node,int par){
    col[node]= 2;
    parent[node]= par;

    for(auto v:g[node]){
        if(v== parent[node])continue;
        if(col[v]==1){
            dfs(v,node);
        }else if(col[v] == 2){
            ////there exists a cycle
            int temp = node;
            while(temp != v){
                cycle.push_back(temp);
                temp = parent[temp];
            }
            cycle.push_back(temp);
            reverse(cycle.begin(),cycle.end());
        }
    }

    col[node]=3;
}

void solve(){

    int n,m;
    cin>>n>>m;
    g.clear();
    g.resize(n+1);
    col.assign(n+1,1);
    parent.assign(n+1,0);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        map<pair<int,int>,int> edgecnt;
        if(a>b) swap(a,b);
        edgecnt[{a,b}]++;

        if(a==b){
            //self loop
        }else if(edgecnt[{a,b}] > 1){
            //multiple edges
        }else {
            g[a].push_back(b);
            g[b].push_back(a);
        }

       

    }
    
    for(int node =1;node<=n;node++){
        if(col[node]== 1){
            dfs(node,0);
        }
    }

    for(auto v: cycle){
        cout<<v<<" ";
    }
    cout<<endl;

    
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
    solve();
}



// learn how to handle self loop 
// how to handle multi edge
// cycle find and print in directed
// cycle find and print in undirected
// count nodes in all  cycles   // not completed