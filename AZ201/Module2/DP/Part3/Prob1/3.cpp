#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int n;
string s;
int arr[100100];
int dp[100100][5];

int rec(int level ,int st){
    if(level == n){
        return 0;
    }

    if(dp[level][st] != -1){
        return dp[level][st];
    }
    int ans = 0;

    if(st == 0){
        if(s[level] == 'h'){
            ans = min(rec(level+1,1), arr[level] + rec(level+1,0));
        }else {
            ans = rec(level+1,0);
        }

    }else if(st ==1){
        if(s[level] == 'a'){
            ans = min(rec(level+1,2), arr[level] + rec(level+1,1));
        }else {
              ans = rec(level+1,1);
        }

    }else if(st == 2){
        if(s[level] == 'r'){
            ans = min(rec(level+1,3), arr[level]+ rec(level+1,2));
        }else {
              ans = rec(level+1,2);
        }

    }else{
         if(s[level] == 'd'){
            ans = arr[level]+ rec(level+1,3);
        }else {
              ans = rec(level+1,3);
        }

    }

    return dp[level][st] = ans;
}

void solve(){
 cin>>n;
 cin>>s;
 for(int i=0;i<n;i++){
     cin>>arr[i];
 }
 for(int i=0;i<n;i++){
     for(int j=0;j<5;j++){
         dp[i][j] =-1;
     }
 }

 cout<<rec(0,0)<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}