#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

void solve(){
	int n;
    cin>>n;
    string s ;
    cin>>s ;

    vector<int> arr[26];

    for(int i=0;i<26;i++){
        arr[i].push_back(-1);
    }

    for(int i=0;i<s.size();i++){
        arr[s[i] - 'a'].push_back(i);
    }

    for(int i=0;i<26;i++){
        arr[i].push_back(n);
    }

    int ans =0;

    for(int i=0;i<26;i++){
        for(int j=1;j<(int)(arr[i].size())-1;j++){
           ans+= (arr[i][j] - arr[i][j-1]) * (arr[i][j+1] - arr[i][j]);
        }
    }
    cout<<ans<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}