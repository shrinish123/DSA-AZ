#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define ii pair<int,int> 
#define F first
#define S second

vector<pair<int,int>> fac(int n){
    
    vector<pair<int,int>> ans;

    for(int i=2;i*i<= n;i++){
        if(n%i == 0){
           int cnt =0;
           while(n%i == 0){
            cnt++;
            n = n/i;
           }

           ans.push_back({i,cnt}); 
        } 
    }
    
    if(n > 1) ans.push_back({n,1});

    return ans;

}

void solve(){
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
       cin>>arr[i];
   }


}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}