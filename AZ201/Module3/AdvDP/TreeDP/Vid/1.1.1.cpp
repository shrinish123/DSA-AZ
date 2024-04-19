#include<bits/stdc++.h>
using namespace std;

#define int long long

int n;
int indp[100100];
int outdp[100100];
vector<int> g[100100];

void indfs(int node,int par){
    indp[node] = 0;

    for(auto v : g[node]){
        if(v != par){
            indfs(v,node);
            indp[node] = max(indp[node],indp[v]+1);
        }
    }
    

}

void outdfs(int node,int par,int outval){
     outdp[node] = outval;

     int max1 = -1,max2 =-1;
     for(auto  v : g[node]){
         if(v != par){
             if(indp[v] > max1){
                 max2 = max1;
                 max1 = indp[v];
             }else if(indp[v] > max2){
                 max2 =indp[v];
             }
         }
     }

     for(auto v : g[node]){
         
         if(v!= par){

              if(indp[v] == max1){
                  outdfs(v,node,max(outdp[node]+1,max2+2));
              }else {
                   outdfs(v,node,max(outdp[node]+1,max1+2));
              }
         }
     }

     
}

void solve(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    indfs(1,0);
    outdfs(1,0,0);

    for(int i=1;i<=n;i++){
        cout<<max(indp[i],outdp[i])<<" ";
    }

    cout<<endl;
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}