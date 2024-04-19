#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"


int n;
int x[101];
int dp[101][100100];

bool rec(int level, int sneed){
    //prning 
    if(sneed < 0) return 0;  // to avoid runtime errors
    //base case 
    if(level == n){
        if(!sneed) return true;
        else return false;
    }

    // cachecheck
    if(dp[level][sneed] != -1){
        return dp[level][sneed];
    }


    //trans

    bool ans = rec(level+1,sneed);


    ans = ans || rec(level+1,sneed-x[level]);

    
    //save and return 
    return dp[level][sneed] = ans;
}

vector<vector<int>> allSol;
vector<int> curSol;

void generate(int level,int sneed){
    if(level == n){
        allSol.push_back(curSol);
        return;
    }

    if(rec(level+1,sneed)){
        generate(level+1,sneed);
    }
    if(rec(level+1,sneed-x[level])){
        curSol.push_back(x[level]);
        generate(level+1,sneed-x[level]);
        curSol.pop_back();
    }
}


void solve(){
  cin>>n;
  for(int i=0;i<n;i++){
      cin>>x[i];
  }

  memset(dp,-1,sizeof(dp));
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}