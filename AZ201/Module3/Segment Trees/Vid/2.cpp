#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define ii pair<int,int> 
#define F first
#define S second
#define all(a) a.begin(),a.end()

struct node{
    int mn;
    int cnt;
      
    node(int m = 1e9,int c=0 ){
      mn = m;
      cnt = c;
    } 
};

int n;
int arr[100100];
node t[400400];

node merge(node a , node b){

    if(a.mn == b.mn) return node(a.mn, a.cnt+b.cnt);
    else if(a.mn < b.mn) return a;
    return b;
}


void build(int id , int l ,int r){

    if( l == r){
        t[id] = node(arr[l],1);
        return;
    }

    int mid = (l+r)/2;
    build(2*id, l,mid);
    build(2*id+1,mid+1,r);

    t[id] = merge(t[2*id] , t[2*id+1]);
}

void update(int id , int l ,int r, int pos ,int val){

    if(pos < l || pos > r )return;

    if(l == r){
        t[id] = node(val,1);
        arr[l] = val;
        return;
    }

    int mid = (l+r)/2;
    update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);
    t[id] = merge(t[2*id],t[2*id+1]);
}

node query(int id , int l , int r, int lq, int rq){
   
    if(rq < l || lq > r) return node(1e9,0);

    if(l >=lq && r <= rq){
        return t[id];
    }
    
    int mid = (l+r)/2;
    node left = query(2*id,l,mid, lq, rq);
    node right = query(2*id+1,mid+1,r,lq,rq);
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
     node ans = query(1,0,n-1,l,r);
     cout << ans.mn << " " << ans.cnt << endl;
   }
  }
}


// Point update range Query
// 1 x v -> xth position with val v
// 2 l r -> min value and count of min 

// 1 3 2 2 2

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