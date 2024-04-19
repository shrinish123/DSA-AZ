#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define ii pair<int,int>
#define F first
#define S second

int dist(int x,int y){
    return x*x + y*y;
}

int bs(vector<int> &arr, int n,int val){

    int l=0; int r = n-1;
    int ans = n;

    while(l<=r){
        int mid = l + (r-l) / 2;
        if(arr[mid] <= val){
            l = mid +1;
        }
        else{
            r = mid-1;
            ans = mid;
        }
    }
    return ans;
}


void solve(int t){

   int cntred = 0;
   int cntyel =0;

   int rs, rh;
   cin>>rs>>rh;

   int n;
   cin>>n;
   vector<ii> red;
   vector<int> distr;
   for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    red.push_back({x,y});
    if(dist(x,y) <= (rs+rh)*(rs+rh)){
        distr.push_back({dist(x,y)});
    }
    
   }

   int m;
   cin>>m;
   vector<ii> yel;
   vector<int> disty;
   for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    yel.push_back({x,y});
     if(dist(x,y) <= (rs+rh)*(rs+rh)){
        disty.push_back({dist(x,y)});
    }
   }

   sort(distr.begin(),distr.end());
   sort(disty.begin(),disty.end());

   for(int i=0;i<distr.size();i++){
       
      int cnt =  bs(disty,disty.size(),distr[i]);

      if(cnt== 0) cntred++;
   }

    for(int i=0;i<disty.size();i++){
       
      int cnt =  bs(distr,distr.size(),disty[i]);

      if(cnt== 0) cntyel++;
   }
   
   
   

   


    //ans 
    cout<<"Case #"<<t<<": "<<cntred <<" "<<cntyel<<endl;

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