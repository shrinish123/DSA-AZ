#include<bits/stdc++.h>
using namespace std;

#define int long long
int fib[55];

void solve(){
    
    fib[0] =1;
    fib[1] =1;
    for(int i=2;i<=50;i++){
        fib[i] = fib[i-1] + fib[i-2];
    } 

    
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}