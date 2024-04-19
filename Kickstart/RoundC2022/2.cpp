#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'

int n,x,y;
vector<int> sol;
int dp[5001][10000];
int saved[5001][10000];

bool rec(int level,int sneed){
    // pruning
    if(sneed<0)return 0;
    // base
    if(level > n){
      if(sneed==0)return 1;
      return 0;
    }
    // cache check
    if(saved[level][sneed]){
        return dp[level][sneed];
    }
    // transition
    bool ans = rec(level+1,sneed) || rec(level+1,sneed-level);
    // save and return
    saved[level][sneed] = 1;
    dp[level][sneed] = ans;
    return ans;
}


void generate(int level,int sneed){
    if(level > n){
        return;
    }
    if(rec(level+1,sneed)){
      // don't take move.
      generate(level+1,sneed);
    }
    else{// take move.
      sol.push_back(level);
      generate(level+1,sneed-level);
    }
}

void init(){
    sol.clear();
    memset(dp,0,sizeof(dp));
    memset(saved,0,sizeof(saved));
}

void solve(int t){

  
  cin>>n>>x>>y;
  init();
  int a = n*(n+1)/2;
   
  int sum = (a * x)/(x+y);
  
  if((a*x)% (x+y) == 0){
      
      if(rec(1,sum)){
           generate(1,sum);
          
            cout<<"Case #"<<t<<": "<<"POSSIBLE"<<endl;
            cout<<sol.size()<<endl;
            for(auto v :sol){
                cout<<v<<" ";
            }
            cout<<endl;
      }
      else {
            cout<<"Case #"<<t<<": "<<"IMPOSSIBLE"<<endl;
      }
  }
  else {
          cout<<"Case #"<<t<<": "<<"IMPOSSIBLE"<<endl;
  }


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