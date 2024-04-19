#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'




void solve(){
  string s;
  cin>>s; 
  int n =s.size();
  int kmp[n+1];

  int i=0;int j=-1; kmp[0] = -1;

  while(i<n){
      while(j != -1 && s[i] != s[j]) j = kmp[j];
      i++;j++;
      kmp[i] = j;
 }
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    string temp;getline(cin,temp);

    while(t--) 
        solve();
    
   
}