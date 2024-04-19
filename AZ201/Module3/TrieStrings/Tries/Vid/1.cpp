#include<bits/stdc++.h>
using namespace std;

#define int long long

struct node(){
    node * child[26];
    int prefix;
    vector<string> wend;

    node(){
        prefix =0;
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
    }
};

struct trie(){
    node *t;
    trie(){
        t =new node;
    }

    void insert(string s){

    node *cur =root;

    for(int i=0;i<s.size();i++){
        cur->prefix++;

        int x = s[i] - 'a';

        if(cur->child[x] == NULL){
            cur->child[x] = new node;
        }
        cur = cur->child[x];
    }
    cur->wend.push_back(s);
    }
};





void delete(string s){

    node * cur =root;

    for(int i=0;i<s.size();i++){
        cur-> prefix--;

        int x = s[i] -'a';

        cur = cur->child[x];
    }
    cur->wend.pop_back(s);
}

void solve(){
    

    trie();
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}