#include<bits/stdc++.h>
using namespace std;

#define int long long
#define print(arr) for(int i=0;i<arr.size();i++){cout<<arr[i]<<' ';}cout<<endl;

void solve(){
    int n=  1000000;
    int is_prime[1000001];

    for(int i=2;i<=n;i++){
        is_prime[i] = 1;
    }

    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            for(int j =i*i;j<=n;j += i){
                is_prie[j] = 0;
            }
        }
    }

    // for totient

    int phi[n+1];

    for(int i=1;i<=n;i++){
        phi[i] = i;
    }

    for(int i=2;i<=n;i++){
        if(is_prime[i]){

            for(int j=i;j<=n;j+=i){
                phi[j] -= phi[j]/i;
            }
        }
    }
    
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}