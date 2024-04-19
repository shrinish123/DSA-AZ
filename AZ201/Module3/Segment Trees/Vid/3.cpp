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
int dif[100100];
int t[400400];

void update(int id,int l, int r, int pos ,int val){
   if(pos < l || pos > r) return;

   if(l == r){
    t[id] += val;
    dif[l] += val;
    return;
   }

   int mid = (l+r)/2;
   update(2*id, l,mid,pos,val);
   update(2*id+1,mid+1,r,pos,val);
   t[id] = t[2*id] + t[2*id+1]; 
}

void query(int id ,int l ,int r , int lq, int rq){
    if(rq < l || lq > r) return 0;

    if(lq >= l && rq <= r) return t[id];

    int mid = (l+r)/2;
    return query(2*id,l,mid,lq,rq) + query(2*id+1,mid+1,r,lq,rq);
}



void solve(){
  cin>>n; 
  for(int i=0;i<n;i++) cin>>arr[i];

  int q;
  cin>>q;

  while(q--){
    int t;
    cin>>t;

    if(t == 1){
        int l,r,v;
        cin>>l>>r>>v;

        update(1,0,n-1,l,v);
        update(1,0,n-1,r+1,-v);
    }
    else{
       int x; cin>>x;
       return arr[x] + query(1,0,n-1,0,x);
    }
  }

}

// Uses Point update Range Query only (looks diffrent)
// Range update Point Query (uses partial sum + PURQ)
// 1 l r v -> add v to pos from l to r 
// 2 x -> find val at pos x 


//Here we build a seg tree on diff arr and then find pre sum for query


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