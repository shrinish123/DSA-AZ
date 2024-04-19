#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'


void solve(int t){

   int ans=0;
    int m,n,p;
    cin>>m>>n>>p;
    p--;
    int arr[m][n];

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int  i=0;i<n;i++){
        int high= 0;
        int john = arr[p][i];
        for(int j=0;j<m;j++){
          high = max(high, arr[j][i]);
        }

        ans += (high- john);
    }
   


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