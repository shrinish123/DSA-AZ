#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'




void solve(int t){

   int ans=0;

   int n;
   cin>>n;

   vector<pair<string,int>> col;
   vector<pair<int,int>> dur;

   for(int i=0;i<n;i++){
    string c;
    int d; 
    int u;
    cin>>c>>d>>u;
     
    col.push_back({c,u});
    dur.push_back({d,u});
   }

   sort(col.begin(),col.end());
   sort(dur.begin(),dur.end());


  for(int i=0;i<n;i++){

       
  

    if(col[i].second == dur[i].second){
      ans++;
    }
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