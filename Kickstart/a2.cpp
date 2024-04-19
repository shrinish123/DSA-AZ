#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    string s1,s2;
    cin>>s1>>s2;
    int flag =1;

     int a1[26] = {0};
     int a2[26] = {0};

    if(s1.size() != s2.size()){
       flag =0;
    }else {


        for(int i=0;i<s1.size();i++){
            a1[s1[i]-'a']++;
        }
        for(int i=0;i<s2.size();i++){
             a2[s2[i]-'a']++;
        }

        for(int i=0;i<26;i++){
           if (abs (a1[i] - a2[i]) > 3){
                flag =0;
           }
        }
    }

    if( flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int _t;cin>>_t;while(_t--)
    solve();
}