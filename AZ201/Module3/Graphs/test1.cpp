#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'




void solve(){
    string num;
    cin>>num;
    int n = num.size();
        string ans=" ";
        
        for(int i=0;i<n-2;i++){
            if(num [i] == num[i+1] &&  num[i+1]== num[i+2] && num[i] > ans[0]){
                ans ="";
               
                for(int j=0;j<3;j++){
                    ans+= num[i];
                }
            }
        }
        cout<<ans<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // string temp;getline(cin,temp);

    // while(t--) 
        solve();
    
   
}