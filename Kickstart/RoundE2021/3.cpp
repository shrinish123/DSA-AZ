#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define F first
#define S second
#define ii  pair<int,int>

vector<vector<int>> g;
vector<string> grid;
int n,m;


void solve(int t){
   cin>>n>>m;
   grid.resize(n+1);

   for(int i=0;i<n;i++){
    cin>>grid[i];
   }
    
    
   
  
   cout<<"Case #"<<t<<": "<<sum%m<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
      solve(i);
    }
}