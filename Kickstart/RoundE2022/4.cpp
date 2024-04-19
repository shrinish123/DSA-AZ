#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define ii pair<int,int> 
#define F first 
#define S second



int checkop(string op){

    if( op == "*")return 1;
    else if( op == "+") return 2;
    else if( op == "-") return 3;
    else return 4;
}

void solve(int t){

   int n,p,m,ar,ac;
   cin>>n>>p>>m>>ar>>ac;

   vector<pair<int,ii> dir;
   
   for(int i=0;i<4;i++){
    string opd; int k;
    cin>>opd >>k;
    dir.push_back({i,{checkop(opd),k}});
   }
   
    
    



  

   for(int i=0;i<p;i++){
     int x,y,c;
     cin>>x>>y>>c;
   }


  
   cout<<"Case #"<<t<<": "<< 0<<endl;
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