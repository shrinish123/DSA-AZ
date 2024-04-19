#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

void solve(){
	int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

   vector<vector<int>> ans;
    sort(a,a+n);
    set<vector<int>> s;

    for(int j=0;j<n;j++){
         int i=0;
         int k =n-1;

        while(i<j && j< k ){
            if(a[i]+a[j]+a[k] == 0){
                vector<int> sol;
                sol.push_back(a[i]);
                sol.push_back(a[j]);
                sol.push_back(a[k]);
                s.insert(sol);
                i++;
                k--;
                
            }
            else if(a[i]+a[j]+a[k] < 0){
               i++;
            }else {
                k--;
            }

        }
    }

    for(auto it = s.begin();it!=s.end();it++){
        ans.push_back(*it);
    }

    for(auto v : ans){
        for(auto x : v){
            cout<<x <<" ";
        }
        cout<<endl;
    }
} 

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}