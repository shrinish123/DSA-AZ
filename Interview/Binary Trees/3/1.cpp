#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define ii pair<int,int> 
#define F first
#define S second
#define all(a) a.begin(),a.end()


// Zigzag Traversal // Spiral Traversal

class node{
    public : 
    int data;
    node* left;
    node* right;

    node(int x){
        this -> data = x; 
        this->left = NULL;
        this->right = NULL;
    }
};

void build(node* &root){
    int x; cin>>x;
    if(x == -1) return;

    root = new node(x);
    build(root->left);
    build(root->right);
}

void zigzagTraversal(node *root){

    deque<pair<node*,int>> dq;
    int dis =0;
    int dir = 0;
    dq.push_back({root,0});

    while(!dq.empty()){
            
            auto curNode = dq.back();
            dq.pop_back();
            
            if(curNode.S > dis ){
                cout << endl;
                dis = curNode.S;
                dir = dir == 0 ? 1 : 0;
            }
            cout << curNode.F-> data << " ";
        
        if(dir == 0){
          if(!root->left){
            dq.push_back({root->left,curNode.S+1});
          }
          if(!root->right){
            dq.push_back({root->right,curNode.S+1});
          }
        }
        else{
            if(!root->right){
            dq.push_front({root->right,curNode.S+1});
          }
          if(!root->left){
            dq.push_front({root->left,curNode.S+1});
          }
        }
        
    }
}


void solve(){
   node *root = NULL;
   build(root);

   zigzagTraversal(root);
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    solve();
    // cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}