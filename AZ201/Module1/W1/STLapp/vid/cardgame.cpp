#include<bits/stdc++.h>
using namespace std;

bool comp (pair<int,int> &a,pair<int,int> &b){
    //returns 1 if a is greater than b
    return a.first+ a.second > b.first+b.second;
}

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr.begin(),arr.end(),comp);
    int finalA=0;
    int finalB=0;

    for(int i=0;i<n;i++){
      if(i%2 ==0){
          finalA+=arr[i].first;
      }else {
          finalB+=arr[i].second;
      }
    }
    cout<<finalA<<" "<<finalB<<" "<<endl;

}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _;cin>>_;
    string temp;
    getline(cin,temp);
    while(_--)
    solve();

}