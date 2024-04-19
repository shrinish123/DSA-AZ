#include<bits/stdc++.h>
using namespace std;

#define int long long
int grid[10][10];



void solve(){

    for(int i=0;i<9;i++){
        string s;
        cin>>s;
        for(int j=0;j<9;j++){
            if(s[j] != '.'){
                grid[i][j] = s[j];
            }
        }
    }
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}