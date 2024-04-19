#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define ii pair<int,int> 
#define F first
#define S second
#define all(a) a.begin(),a.end()

int N = 1e5;
vector<int> t[4*N];
vector<int> arr;


void solve(){
  int n,q; cin>>n>>q; 
  arr.resize(n);
  for(int i=0;i<n;i++) cin>>arr[i];
}

// Q : l,r,x -> Find the smallest number greater or equal to a specified number. No modification queries.



signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
     #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
     #endif
    int _t;cin>>_t;while(_t--)
    solve();
    // cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}