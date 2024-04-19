#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'


void solve(int t){

   string s;
   int n;
   cin>>n>>s;
   int arr[n];
   arr[0]=1;
   int count =1;
   for(int i=1;i<s.size();i++){
       if(s[i] > s[i-1]){
           count++;
       }else {
           count =1;
       }
        arr[i] = count;
   }
   

   


    //ans 
    cout<<"Case #"<<t<<": ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

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