#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define MOD  1e9+7

// To find a^b % MOD
int binexp(int a,int b,int mod){
    int ans =1;

    while(b){
        if(b%2 == 1){
            ans = ans*a %mod;
        }
        a = a*a %mod;
        b=b/2;
    }
    return ans;
}

//to find nCr % mod 





void solve(){


    //To find inverse 
    int a;cin>>a;

    //inverse 
    // a^-1 % mod === a^(mod -2) % mod  
    cout<<binexp(a,mod-2,mod);


    // To find nCr



}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _;cin>>_;
    string temp;
    getline(cin,temp);
    while(_--)
    solve();

}