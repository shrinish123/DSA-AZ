#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin>>n;
    
    set<int> st;

    for(int i=1;i*i<=n;i++){
        if(n%i ==0){
            st.insert(i);
            if(i*i != n){
                st.insert(n/i);
            }
        }
    }

    for(auto v:st){
        cout<<v<<" ";
    }
    cout<<endl;
    
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int _t;cin>>_t;while(_t--)
    solve();
}

// /
//  Prin all factors of no in ascending order
