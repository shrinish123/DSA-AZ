#include<bits/stdc++.h>
using namespace std;

#define int long long
#define print(arr) for(int i=0;i<arr.size();i++){cout<<arr[i]<<' ';}cout<<endl;

void solve(){
    
    int a,b;
    cin>>a>>b;

    int n = 1000100;

    int primes[1000100];
    for(int i=0;i<=n;i++){
        primes[i] = 1;
    }
  
    for(int i=2;i<= n;i++){
       if(primes[i]){
          
          for(int j = i*i; j<=n;j += i){
            primes[j] = 0;
          }
       }
    }
    ///for range a to b
    int isprime[n];
    for(int i=0;i<n;i++){
        isprime[i] = 1;
    }
   
    for(int i=2;i<n;i++){
        if(primes[i]){

            int curMul =  ((a+i-1) /i) *i;

            while(curMul <= b){
                if(!primes[curMul]){
                    isprime[curMul-a] =0;
                }
                curMul += i;
            }
        }
    }
    
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}