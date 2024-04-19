#include<bits/stdc++.h>
using namespace std;

#define int long long

int pow2[52];

void solve(){
    int n,l,r;

    cin>>n>>l>>r;
    
    int minans= 0;
    int maxans =0;

   minans+= pow2[l] -1;
   minans += (n-l);

   maxans += pow2[r] -1;
   maxans += pow2[r-1] * (n-r);

   cout<<minans<<" "<<maxans<<endl;

    


    


}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    pow2[0]= 1;
    for(int i=1;i<52;i++){
       pow2[i] = pow2[i-1]*2;
    }
    int _t;cin>>_t;while(_t--)
    solve();
}