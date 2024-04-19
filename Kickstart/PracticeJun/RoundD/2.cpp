#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'

int n,m;
int a[6010];
int b[6010];
int k;



void solve(int t){

   int ans;

   cin>>n;

   for(int i=0;i<n;i++){
       cin>>a[i];
   }
   
   for(int i=0;i<m;i++){
       cin>>b[i];
   }
   
   cin>>k;

   



    //ans 
    cout<<"Case #"<<t<<": "<<ans<<endl;

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    string temp;
    getline(cin,temp);
    for(int i=1;i<=t;i++){
        solve(i);
    }
}