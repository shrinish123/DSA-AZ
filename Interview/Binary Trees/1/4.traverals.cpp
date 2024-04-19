#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define ii pair<int,int> 
#define F first
#define S second
#define all(a) a.begin(),a.end()

class node{
   public :
   int data;
   node* left;
   node* right;

   node(int x ){
    this-> data = x;
    this->left = NULL;
    this->right = NULL;
   }
};

node* buildTree(node* root){
    int x ; cin>>x;

    if( x == -1){
        return NULL;
    }
    root = new node(x);

    root-> left = buildTree(root->left);
    root->right = buildTree(root-> right);
    return root;
}

void inorder(node* root){

    if(!root){
        return;
    }
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root-> right);
}

void preorder(node* root){

    if(!root){
        return;
    }
    
    cout<< root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){

   if(!root){
    return;
   }

   postorder(root->left);
   postorder(root->right);
   cout << root->data << " ";
}

int leafNodes = 0;
vector<int> leaves;

void countLeaves(node* root){
     
    int cnt = 0;

    if(root -> left != NULL){
        countLeaves(root->left);
    }
    else cnt++;

     if(root ->right != NULL){
        countLeaves(root-> right);
    }
    else cnt++;

    if(cnt == 2){
        leafNodes++;
        leaves.push_back(root->data);
    }

}


void solve(){
    
    node* root = NULL;

    root = buildTree(root);

    inorder(root);
    cout << endl;

    preorder(root);
    cout << endl;

    postorder(root);
    cout << endl;
    
    countLeaves(root);

    cout << leafNodes << endl;
    for(auto v : leaves) cout <<  v  << " "; cout << endl;


}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
     
    solve();
    // cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}