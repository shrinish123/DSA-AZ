#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define end "\n"

void solve(){
	int n;
    cin>>n;
    string s;
    cin>>s;

    map<char,int> mp;
    int ans =0;
    for(int i=0;i<n;i++){
        if(mp[s[i]] > 0){
           ans+= (n-i);
           cout<<"contribution at i ="<<i <<" is "<<n-i<<endl; 
           cout<<"ans "<<ans<<endl;
        }
        else {
            mp[s[i]]++;
            ans+= (i+1)*(n-i);
             cout<<"contribution at i ="<<i <<" is "<<(i+1)*(n-i)<<endl; 
            cout<<"ans "<<ans<<endl;

        }
    }

    cout<<ans<<endl;
   
   
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}