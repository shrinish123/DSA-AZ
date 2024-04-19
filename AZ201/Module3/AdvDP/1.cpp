#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,d;
int arr[100100];
int dp[100100];
int saw[100100];

vector<int> sol;

int rec(int level){
    if(level > n-1){
        return 0;
    }
    if(level == n-1){
        return 1;
    }

    if(dp[level] != -1){
        return dp[level];
    }

    int ans =0;
    for(int j = level + 1;j<n;j++){
        if(abs (arr[j] - arr[level]) >= d){
            if(ans < 1 + rec(j)){
                ans = 1+ rec(j);
                saw[level] =j;
            }
        }
       
    }

    return dp[level] =ans;
}

void gensol(int level){
    if(level > n-1){
        return;
    }
    if(level == n-1){
        sol.push_back(n-1);
        return;
    }

    sol.push_back(level);
    gensol(saw[level]);
}

void solve(){
    cin>>n>>d;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    memset(dp,-1,sizeof(dp));

    cout<<rec(0)<<endl;
    gensol(0);
    
    for(int i=0;i<sol.size();i++){
        cout<<sol[i]+1<<" "; 
    }
    cout<<endl;
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int _t;cin>>_t;while(_t--)
    solve();
}