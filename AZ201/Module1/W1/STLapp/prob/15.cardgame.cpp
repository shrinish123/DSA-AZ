#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'

bool comp (pair<int,int> &a ,pair<int,int> &b ){
    return  a.first +a.second > b.first + b.second; 
}

void solve(){
  
   int n;
   cin>>n;
   vector<pair<int,int>> arr(n);
   for(int i=0;i<n;i++){
       cin>>arr[i].first;
   }
   for(int i=0;i<n;i++){
       cin>>arr[i].second;
   }

   sort(arr.begin(),arr.end(),comp);

int afinal =0;int bfinal =0;
   for(int i=0;i<n;i++){
       if(i%2 ==0){
          afinal+= arr[i].first;
       }else {
           bfinal+= arr[i].second;
       }
   }

   if(afinal - bfinal > 0){
       cout<<"Alice"<<endl;
   }else if(afinal - bfinal == 0){
       cout<<"Tie"<<endl;
   }else {
       cout<<"Bob"<<endl;
   }





}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _;cin>>_;
    string temp;
    getline(cin,temp);
    while(_--)
    solve();

}