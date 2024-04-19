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
    public: 
    int data; 
    node *left;
    node *right;

    node(int x){
        this -> data = x;
        this -> left = NULL;
        this-> right = NULL;
    }
};

void build(node* &root){
    int x; 
    cin>>x;
    if(x == -1) return;

    root = new node(x);

    build(root->left);
    build(root->right);
}

// Q1 : Find Height
int ht(node *root){

    if(!root){
      return 0;
    }

    int h1 = ht(root->left);
    int h2 = ht(root->right);

    return max(h1,h2) + 1;
}


int diameter(node *root){

  if(!root){return 0;}

  int d1 =  diameter(root->left);
  int d2 = diameter(root-> right);

  int h1 = ht(root->left); int h2 = ht(root->right);

  return max({d1,d2,1+h1+h2});
}

ii diameterFast(node *root){
    if(!root){ return {0,0};}

    auto left = diameterFast(root->left);
    auto right = diameterFast(root->right);

    return {max({left.F,right.F,left.S+right.S+1}),max(left.S,right.S)+ 1};
}

ii balanced(node * root){
    if(!root) return {1,0}; 

    auto left = balanced(root->left);
    auto right = balanced(root->right);
    bool check = abs(left.S-right.S) <= 1 && left.F && right.F;
    return { check,max(left.S,right.S) + 1};

}

bool isIdentical(node *root1, node *root2){
    if(!root1 && !root2){
        return 1;
    }

    if(root1 && root2){
          return root1->data == root2-> data && isIdentical(root1->left,root2->left) && isIdentical(root1-right,root2->right); 
    }
    return 0;
}



void solve(){
  
  node *root = NULL;
  build(root);

  cout << "Height : " << ht(root) << endl;

  cout << "Diameter : " << diameter(root) << endl;

  cout << "Diameter Fast : " << diameterFast(root).F << endl;

  cout << "Is Balanced : " << balanced(root).F << endl; 
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    // cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}