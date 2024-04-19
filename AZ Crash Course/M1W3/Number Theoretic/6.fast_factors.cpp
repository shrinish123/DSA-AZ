#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<int> primeFact(int x){

    vector<int> ans;

    while(x > 1){
        ans.push_back(sp[x]);
        x = x/sp[x];
    }
    return ans;
}

//   x =  sp[x] * x/(sp[x]);

void solve(){
    
    int n = 1000100;

    int sp[n];

    for(int i=2;i<=n;i++){
        sp[i] = i;
    }

    for(int i=2;i<=n;i++){
        if(sp[i] == i){

            for(int j=i*2;j<=n;j+=i){
                if(sp[j] == j){
                    sp[j] = i;
                }
            }
        }
    }


}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}