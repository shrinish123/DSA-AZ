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
   int sum,mx,lazy;

   node(int s=0 ,int m=0,int l=0){
    sum =s; mx = m; lazy = l;
   }
};


int n;
node t[400400];
int arr[100100];

node merge(node a ,  node b){
    int s = a.sum + b.sum;
    int mx = max(a.mx,b.mx);
    node ans = node(s,mx,0);
    return ans;
}

void push(int id ,int l, int r){

    if(t[id].lazy){
        t[id].sum = t[id].lazy*(r-l+1);
        t[id].mx = t[id].lazy;
        
        if(l != r){
          t[2*id].lazy = t[id].lazy;
          t[2*id+1].lazy = t[id].lazy;
        }
        t[id].lazy = 0;
    }
}

void build(int id, int l ,int r){

    if(l == r){
        t[id] = node(arr[l],arr[l],0);
        return;
    }

    int mid = (l+r)/2; 
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    t[id] = merge(t[2*id],t[2*id+1]);
}

void update(int id ,int l , int r ,int lq, int rq ,int v ){
    push(id,l,r);
    if(rq < l || lq > r) return;
    if(l>=lq && r <= rq){
        t[id].lazy = v;
        push(id,l,r);
        return;
    } 

    int mid = (l+r)/2;
    update(2*id,l,mid,lq,rq,v);
    update(2*id+1,mid+1,r,lq,rq,v);
    t[id] = merge(t[2*id],t[2*id+1]);
}

node query(int id , int l , int r ,int lq ,int rq){
    push(id,l,r);

    if(rq <l || lq > r) return node();
    if(l >=lq && r <= rq){
        return t[id];
    }

    int mid = (l+r)/2;
    return merge(query(2*id,l,mid,lq,rq), query(2*id+1,mid+1,r,lq,rq));
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
        int l,r;
        cin>>l>>r;
        l--;r--;
        cout << query(1,0,n-1,l,r).sum << endl; 
    }
    else if(t == 2){
        int l,r;
        cin>>l>>r;
        l--;r--;
        cout << query(1,0,n-1,l,r).mx << endl;
    }
    else{
        int l,r,v;
        cin>>l>>r>>v;
        l--;r--;
        update(1,0,n-1,l,r,v);
    }
  }
}

 
// Lazy propagation  (Range update Range Query)
// 1 l r -> find sum from l to r 
// 2 l r -> find max from l to r 
// 3 l r v -> update all pos from l to r as v 



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