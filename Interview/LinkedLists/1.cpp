#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define ii pair<int,int> 
#define F first
#define S second
#define all(a) a.begin(),a.end()


class Node{
   public:

   int data;
   Node* next;

   Node(int data, Node* next){
    this->data = data;
    this->next = next;
   }

   Node(int data){
    this->data = data;
    this->next = nullptr;
   }
};

void solve(){
    
    Node* nn = new Node(5);
    
    cout << nn->data << " " << nn->next << " " << nn << endl;
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
     #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
     #endif
    int _t=1;cin>>_t;while(_t--)
    solve();
    // cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}