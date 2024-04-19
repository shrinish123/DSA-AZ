#include<bits/stdc++.h>
using namespace std;

#define int long long
#define print(arr) for(int i=0;i<arr.size();i++){cout<<arr[i]<<' ';}cout<<endl;

vector<int> div(int n){
     vector<int> divisors;

    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
           divisors.push_back(i);

           if(i*i !=n ){
            divisors.push_back(n/i);
           }
        }
    }

    return divisors;
}



void solve(){
    
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}