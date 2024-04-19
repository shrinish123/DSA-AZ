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
   public : 
   int data;
   node* left;
   node* right;

   Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
   }

};


Node* build(Node* root){

    int x; cin>>x;

    if( x == -1){
     return NULL;
    }

    root = new Node(x);

    root->left  = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

void solve(){
  
  Node* root = NULL;

  root = buildTree(root);
  
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    // cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}