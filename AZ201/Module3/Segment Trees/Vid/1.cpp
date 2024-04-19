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
int t[400400];

void build(int id ,int l ,int r){
    if(l==r){
        t[id] = arr[l];
        return;
    }

    int mid = (l+r)/2;

    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    t[id] = t[2*id] + t[2*id+1];  // merge 
}

void update(int id , int l ,int r , int pos , int val){
    if(pos < l || pos > r) return ;

    if(l == r){
      t[id] = val;
      arr[l] = val;
      return;
    }

    int mid = (l+r)/2;
    update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);
    t[id] = t[2*id] + t[2*id +1]; // merge 
}

int query(int id , int l ,int r , int lq, int rq){

    if(rq < l  || lq > r) return 0;

    if(l>= lq && r<= rq) return t[id];

    int mid = (l+r)/2; 
    return query(2*id,l,mid,lq,rq) + query(2*id+1,mid+1,r,lq,rq);
}


void solve(){
  cin>>n;
  for(int i=0;i<n;i++) cin>>arr[i];

  build(1,0,n-1);

  int q;
  cin>>q;

  while(q--){
    int t;
    cin>>t;

    if(t == 1){
        int x,v;
        cin>>x>>v;
        update(1,0,n-1,x,v);
    }
    else{
        int l,r;
        cin>>l>>r;
        cout << query(1,0,n-1,l,r) << endl;
    }
  }
}

// Point update Range Query
// 1 x v -> update xth position with v 
// 2 l r -> sum of range l to r 



signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //  #ifndef ONLINE_JUDGE
    //  freopen("input.txt", "r", stdin);
    //  freopen("error.txt", "w", stderr);
    //  freopen("output.txt", "w", stdout);
    //  #endif
    // int _t;cin>>_t;while(_t--)
    solve();
    // cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}