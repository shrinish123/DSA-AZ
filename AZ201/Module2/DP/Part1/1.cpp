#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
#define F first
#define S second

int n,k,b;
vector<pair<int,int>> a;
int dp[101][1001][101];


int rec(int level,int cost,int siz){

    //pruning 

    //base case 
   if(level == n){
       return 0;
   }
    
    //cache check 

    if(dp[level][cost][siz] != -1){
        return dp[level][b][siz];
    }

    //transitions 

    int ans = rec(level+1,cost,siz);

    if(cost + a[level].F <= b && siz < k ){
        ans = max(ans,a[level].S + rec(level+1,cost+a[level].F,siz+1));
    }

   //save and return 
    return dp[level][cost][siz] = ans;
}

void solve(){
  cin>>n>>k>>b;
  a.resize(n);
  
  for(int i=0;i<n;i++){
      int p,h;
      cin>>p>>h;
      a[i] = {p,h};
    
  }
 
  memset(dp,-1,sizeof(dp));

  cout<<rec(0,0,0)<<endl;


}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}