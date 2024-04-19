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

    node (int val){
        this -> data = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root){

    int x ; cin >> x ;
    cout << x << endl;
    root = new node(x);

    if(x == -1) return NULL;

    root -> left = buildTree(root-> left);
    root -> right = buildTree(root-> right);
    return root;
}

vector<int> lvlOrderTraversal;

void levelOrderTraversal(node* root){

    queue<pair<node*,int>> q;
    q.push({root,0});
    int curDis = 0;
    
    while(!q.empty()){
        auto curNode = q.front();
        q.pop();
        
        if(curNode.S > curDis ){
            curDis = curNode.S;
            cout << endl;
        }
        cout  << curNode.F-> data << " ";

        if(curNode.F->left != NULL){
            q.push({curNode.F-> left,curNode.S+1});
        }
        if(curNode.F->right != NULL){
            q.push({curNode.F->right,curNode.S+1});
        }
    } 
}


void solve(){

  node* root = NULL;
 
  root = buildTree(root);

  levelOrderTraversal(root);

  for(auto v : lvlOrderTraversal) cout << v << " " ; cout << endl; 
}




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