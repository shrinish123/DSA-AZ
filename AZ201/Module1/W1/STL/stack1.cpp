#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 

void solve(){
    int q;
    cin>>q;
    stack <int> st;
    while(q--){
        string qa;
        cin>>qa;
        if(qa == "add"){
            int x;
            cin>>x;
           st.push(x);
        }
        if(qa == "remove"){
            if(!st.empty()){
                  st.pop();
            }
        }

        if(qa =="print"){
            if(!st.empty()){
                cout<<st.top()<<endl;
            }
            else {
                cout<<0<<endl;
            }
        }
    }
}



signed main() { 

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;
    cin>>_t;
    string temp;
    getline(cin,temp);
    while(_t--)solve(); 
}