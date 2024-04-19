#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define F first
#define S second

int n;

vector<vector<int>> arr;
vector<int> perm;
map<int,int> mp;

void rec(int level){
    if(level == n ){
        arr.push_back(perm);
        return;
    }

    for(auto v: mp){
        if(v.S != 0){
           perm.push_back(v.F);
         
            mp[v.F]--;
           rec(level+1);
           perm.pop_back();
           mp[v.F]++;
        }  
    }
}

void solve(){
 cin>>n;

 for(int i=0;i<n;i++){
   int x;
   cin>>x;
   mp[x]++;
 }

 rec(0);

 //print the vector
 for(auto v :arr){
     for(auto x : v) {
         cout<<x<<" ";
     }
     cout<<endl;
 }
 cout<<endl;
    
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int _;cin>>_;
    // string temp;
    // getline(cin,temp);
    // while(_--)
    solve();

}