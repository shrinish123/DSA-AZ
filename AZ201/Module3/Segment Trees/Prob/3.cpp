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
    int even,odd;

    node(int e=0 , int o = 0){
        even = e;
        odd = o;
    }
};

int n;
int arr[100100];
node t[400400];

node merge(node a , node b){
   return  node(a.even + b.even , a.odd + b.odd);
}

void build(int id , int l , int r){

    if(l == r){
        int isEven = arr[l]%2 == 0;
        t[id] = node(isEven, !isEven);
        return; 
    }

    int mid = (l+r)/2;
    build(2*id, l,mid);
    build(2*id+1,mid+1,r);
    t[id] = merge(t[2*id],t[2*id+1]);
}

void update(int id , int l , int r , int pos , int val){

    if(pos < l || pos > r) return ;

    if(l == r){
        int isEven = val%2 == 0;
        t[id] = node(isEven,!isEven);
        return;
    }

    int mid = (l+r)/2;
    update(2*id,l,mid, pos,val);
    update(2*id+1,mid+1,r,pos,val);
    t[id] = merge(t[2*id],t[2*id+1]);
}

node query(int id , int l ,int r , int lq , int  rq){

    if(rq < l || lq > r) return node();

    if(l >= lq && r <= rq) return t[id];
    
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

    if(t == 0){
      int x,v; cin>>x>>v;
      x--;
      update(1,0,n-1,x,v);
    }
    else if( t==1){
        int l,r;cin>>l>>r;
        l--;r--;

        cout << query(1,0,n-1,l,r).even << endl;
    }
    else{
        int l,r;
        cin>>l>>r;
        l--;r--;
        cout << query(1,0,n-1,l,r).odd << endl;
    }
  }

}

// 0 x y : Modify the number at index x to y.
// 1 l r : Print the count the number of even numbers in range l to r inclusive.
// 2 l r : Print the count the number of odd numbers in range l to r inclusive.



signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
     #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
     #endif
    // int _t;cin>>_t;while(_t--)
    solve();
    // cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}