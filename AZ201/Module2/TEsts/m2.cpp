#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    string s ;

    stack<int> st;
    map<int,int> mp;

    for(int i=0;i<s.size();i++){
         
         if(s[i] == ')'){

             if(!st.empty()){
                st.pop();

                 
             }

         }

         else {

             st.push(1);

         }
    }

}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}