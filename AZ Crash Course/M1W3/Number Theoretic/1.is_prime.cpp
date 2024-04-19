#include<bits/stdc++.h>
using namespace std;

#define int long long
#define print(arr) for(int i=0;i<arr.size();i++){cout<<arr[i]<<' ';}cout<<endl;

bool is_prime(int n){

    for(int i=2;i*i<= n;i++){
        if(n%i == 0){
            return 0;
        }
    }

    return 1;
}

void solve(){
    
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}