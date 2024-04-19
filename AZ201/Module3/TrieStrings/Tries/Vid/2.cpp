#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,maxlen,q;
vector<string> arr;

struct node(){
    node *child[26];
    int prefix;
    vector<string> wend; 

    node(){
        prefix =0;
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
    }
}

struct Trie(){

    node *root;

    Trie(){
        root = new node();
    }

    void insert(string s){
        
        node* cur = root;
       

        for(int i=0;i<s.size();i++){

             cur->prefix++;

            int x = s[i] -'a';

            if(cur->child[x] == NULL){
               cur->child[x] = new node();
            }
            cur = cur->child[x];
        }
        cur-> wend.push_back(s);
    }

    vector<string> ans;


    void dfs(node *cur, int k,string s){

        fif(cur ==NULL) return ;
        if(k==0) return;

        int z
    }



    void find(string s ){


        ans.clear();
        node* cur =root;
       
        for(int i=0;i<s.size();i++){

            int x = s[i] -'a';

            if(cur=>child[x] == NULL ) return ;

            cur = cur->child[x];
        }

        dfs(cur,k,s);

    }
}



void solve(){
    cin>>n>>maxlen>>q;

    Trie T;

  for(int i=0;i<n;i++){
      int a,string s;
     cin>>a>>s;
     T.insert(s);
  }

  while(q--){
      int x,k;
      string s;

      cin>>x>>s>>k;

      for(int i=0;i<s.size();i++){
          string t = s.substr(0,i+1);

          T.find(k,t);

          for(auto v : T.ans){
              cout<<v<<" ";
          }
          
      }
      cout<<endl;
      
  }

}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int _t;cin>>_t;while(_t--)
    solve();
}

//Search enine 
// PRUNE first
// whnever mach prefixes thibk of tries

//DO a dfs in lex frist order

