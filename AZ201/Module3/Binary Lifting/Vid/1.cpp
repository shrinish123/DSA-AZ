#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define ii pair<int,int> 
#define F first
#define S second
#define all(a) a.begin(),a.end()

int n;
int dp[100100][32];
int arr[n];

int find(int x, int k ){
    
    for(int j=31;j>=0;j--){
        if(k&(1<<j)){
            x = dp[x][j];
        }
    }

    return x;
}

void solve(){
  cin>>n;
  for(int i=0;i<n;i++) cin>>arr[i];

  
  //building structure 
  memset(dp,-1,sieof(dp));

  for(int i=n-1;i>=0;i--){
    if(i+1 < n ) dp[i][0] = i+1;

    for(int j=1;j<32;j++){
       dp[i][j] = dp[dp[i][j-1]][j-1];
    }
  } 

  int q;
  cin>>q;
  
  while(q--){
    int x,k;
    cin>>x>>k;
    
    int ind = find(x,k);
    cout << arr[ind] << endl;
  }
  
}


// Basic Binary Lifting on a array
// xk , find kth element after the xth  
//mostly code will runtime as edgecases are not handled


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
     #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("error.txt", "w", stderr);
     freopen("output.txt", "w", stdout);
     #endif
    int _t;cin>>_t;while(_t--)
    solve();
    // cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}