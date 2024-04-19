#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define MOD 1000000007

int fact[200000]; 

int binexp(int a,int b,int mod){
    int ans =1;
    while(b){
        if(b%2==1){
              ans = ans * a %mod;
        }
          a = a*a %mod;
          b =b /2;
    }
  
    return ans;
}


void solve(){
  int n,m; cin>>n>>m;
   int ans = (fact[n+m] * binexp(fact[n],MOD-2,MOD))%MOD;
   ans = ans * binexp(fact[m],MOD-2,MOD)%MOD;
   ans= ans%MOD;
  cout << ((ans%MOD)+MOD)%MOD<<endl;

}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _;cin>>_;
    string temp;
    getline(cin,temp);

    fact[0] = 1;
    for(int i=1;i<200000;i++){
        fact[i] =  (i * fact[i-1])% MOD;
    }

    while(_--)
    solve();
}

    

    
   