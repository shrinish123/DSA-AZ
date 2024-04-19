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
int arr[100100];
int nxt[100100];
int par[100100][25];

void nextGreater(){
    stack<ii> st;

    st.push({arr[0],0});

    for(int i=1;i<n;i++){
       
       while(!st.empty() && st.top().F < arr[i]){
          nxt[st.top().S] = i;
          st.pop();
       }
       st.push({arr[i],i});
    }
    

    while(!st.empty()){
        nxt[st.top().S] = n;
        st.pop();
    }
}

void build(){

    par[n][0] = -1;
    
    for(int i=n-1;i>=0;i--){
        
        par[i][0] = nxt[i];

        for(int j=1;j<20;j++){
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
}

int find(int x , int  k){
     
     for(int i=0;i<25;i++){
        if(k & (1<<i)){
            x = par[x][i];
        }
     }
     return x;
}

void solve(){
  cin>>n;
  for(int i=0;i<n;i++) cin>>arr[i];
  
  nextGreater();
  build();

  int q;
  cin>>q;

  while(q--){
    int x,k;
    cin>>x>>k;
    x--; 
    int ind = find(x,k);
    
    if(ind != -1)cout << arr[ind] << endl;
    else cout << ind << endl;
  } 

}

// More Possibilities
// Idea 1 : kth next greater Element for xth element
// Note : Always keep 1 based indexes to keep 0 as the junk Node.

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //  #ifndef ONLINE_JUDGE
    //  freopen("input.txt", "r", stdin);
    //  freopen("error.txt", "w", stderr);
    //  freopen("output.txt", "w", stdout);
    //  #endif
    int _t;cin>>_t;while(_t--)
    solve();
    // cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}
