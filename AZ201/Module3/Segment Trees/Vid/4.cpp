#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define ii pair<int,int> 
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define INF  1e18

struct node{
   int msum;
   int lsum; 
   int rsum;
   int tsum;

   node(int ms = -INF, int ls = -INF,int rs = -INF,int ts = 0){
      msum = ms;
      lsum = ls;
      rsum = rs;
      tsum = ts;
   }
};

int n;
int arr[100100];
node t[400400];

node merge(node a , node b){
   int ms = max({a.msum, b.msum , a.rsum + b.lsum});
   int ls = max(a.lsum, a.tsum + b.lsum);
   int rs = max(b.rsum, b.tsum + a.rsum);
   int ts = a.tsum + b.tsum;
   return node(ms,ls,rs,ts);
}

void build(int id , int l, int r){

    if(l == r){
        t[id] = node(arr[l],arr[l],arr[l],arr[l]);
        return;
    }

    int mid = (l+r)/2;
    build(2*id, l, mid);
    build(2*id+1,mid+1,r);
    t[id] = merge(t[2*id],t[2*id+1]);
}

void update(int id, int l, int r, int pos , int val){
    
    if(pos < l || pos > r) return;
    
    if( l == r){
        t[id] = node(val,val,val,val);
        return;
    }

    int mid = (l+r)/2;
    update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);

    t[id] = merge(t[2*id],t[2*id+1]);
}

node query(int id ,int l , int r , int lq, int rq){

   if(rq < l || lq > r) return node();

   if(l >= lq && r <= rq){
    return t[id];
   }
    
    int mid = (l+r)/2;
    auto left = query(2*id,l,mid,lq,rq);
    auto right = query(2*id+1,mid+1,r,lq,rq);
    auto ans = merge(left,right);
    return merge(left,right);
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
        x--;
        update(1,0,n-1,x,v);
    }
    else{
        int l,r;
        cin>>l>>r; 
        l--;r--;
        auto ans = query(1,0,n-1,l,r);
        cout << ans.msum << endl;
    }
  }
}

// Point update Range Query
// 1 x v -> arr[x] = v
// 2 l r -> max subarr sum from l to r 


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


//