#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int dp[2020][2020];

int rec(int x,int y){
    if(x==0 && y==0){
        return 0;
    }

    if(dp[x][y] != -1){
        return dp[x][y];
    }


    int win =0;
    for(int i=0;i<=x;i++){
      if(rec(x-i,y) ==0){
          win =1;
      }
    }
      for(int i=0;i<=y;i++){
         if(rec(x,y-i) ==0){
          win =1;
      }
    }
      for(int i=0;i<=min(x,y);i++){
         if(rec(x-i,y-i) ==0){
          win =1;
      }
    }

    return dp[x][y] =win;
}


void solve(){
   int x,y;
   cin>>x>>y;
   cout<<rec(x,y)<<endl;

}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}

//game dp 
//whytoffs game