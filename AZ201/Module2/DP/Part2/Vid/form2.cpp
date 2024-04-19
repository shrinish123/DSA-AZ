#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int n;
 int arr[100100];
int dp[100100];
int saved[100100];

int rec(int level){

	// pruing 

	//base case 

	if(level ==0 ){
		return arr[level];
	}

	//cache
	if(saved[level]){
		return dp[level];
	}

	// transit

	int ans = max(rec(level-1)  + arr[level],arr[level]);

	//save and return 
	saved[level]=1;
	return dp[level] = ans;
}


void solve(){

 cin>>n;
 
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
 
 memset(saved,0,sizeof(saved));
    
	int ans = rec(0);

	
  for(int i=1;i<n;i++){
	  ans = max(ans , rec(i));
  }

  cout<<ans<<endl;

}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}