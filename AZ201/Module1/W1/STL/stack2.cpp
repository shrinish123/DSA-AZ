#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'

void solve(){
    string s;
    cin>>s;
    int ans =0;

    stack<int> st;

    for(int i=0;i<s.size();i++){
        if(s[i] == '('){
            st.push(1);
        }
        else {
            if(!st.empty()){
                st.pop();
            }else {
                ans++;
            }
        }
    }
    ans+=st.size();
    cout<<ans<<endl;
}


signed main(){
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;
    cin>>_t;
    string temp;
    getline(cin,temp);
    while(_t--)solve();

}

