#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define end "\n"

const int MOD = 1000000007;


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
	int n;
    cin>>n;
    int a=0,b=0,c=0,d=0;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    

    for(int i=0;i<31;i++){
        int conta=0,contb=0,contc=0,contd=0;
        int cnt1=0,cnt0=0;
      for(int j=0;j<n;j++){
          
          if(arr[j] & (1<<i)){
              cnt1++;
          }
      }
           cnt0 = n-cnt1;
           conta = (cnt1%MOD * cnt0%MOD * (1<<i) )%MOD;
           if(cnt1) contb = (binexp(2,n-1,MOD) * (1<<i))%MOD;
           contc = ((cnt1%MOD *(cnt1- 1 +MOD)%MOD/2)%MOD  * (1<<i))%MOD;
           contd = ((binexp(2,cnt1,MOD) -1 +MOD)%MOD * (1<<i))%MOD;
            a = (a + conta)%MOD;
            b = (b + contb)%MOD;
            c = (c + contc)%MOD;
            d = (d + contd)%MOD;
      
    }


    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}