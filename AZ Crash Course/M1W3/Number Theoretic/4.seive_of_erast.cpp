#include<bits/stdc++.h>
using namespace std;

#define int long long
#define print(arr) for(int i=0;i<arr.size();i++){cout<<arr[i]<<' ';}cout<<endl;

void solve(){
    int n= 1000100;
    int is_prime[n];
    
    for(int i=2;i<=n;i++){
        is_prime[i] = 1;
    }

    for(int i=2;i<=n;i++){
        if(is_prime[i]){

            for(int j = i*i;j<=n; j += i){
                is_prime[j] = 0;
            }
        }
    }

    // we get array of all primes in O(n log log n);
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}