#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int dp1[2001][2001];


int dp2[2001];
string s;

bool ispal(int l,int r){
    if(l >= r) return 1;

    if(dp1[l][r] != -1){
        return dp1[l][r];
    }

    int ans =0;
    ans = (s[l] == s[r] && ispal(l+1,r-1));

    return dp1[l][r] = ans;
}

int rec(int l){
    if(l == 0){
        return 1;
    }
    if(dp2[l] != -1){
        return dp2[l];
    }

    int ans = l;

    for(int j = l-1 ; j >= 0;j--){
        if(ispal(j+1,l)){
              ans = min(ans, rec(j) +1);
        }
    
    }

    return dp2[l] = ans;
}

void solve(){
  cin>>s;
  int n = s.size();
  memset(dp1,-1,sizeof(dp1));
  memset(dp2,-1,sizeof(dp2));
  cout<<rec(n-1) -1<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}