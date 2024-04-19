#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int n;
vector<int> queen;
int ans =0;
vector<vector<int>> allSol;

bool check(int row,int col){
    for(int i =0;i<queen.size();i++){
        if(col == queen[i] || abs(col-queen[i]) == abs(i -row)){
            return false;
        }
    }

    return true;
}

void rec(int level){
    if(level == n){
        ans++;
        allSol.push_back(queen);
    }

    for(int i=0;i<n;i++){
        if(check(level,i)){
            queen.push_back(i);
            rec(level+1);
            queen.pop_back();
        }
    }
}

void solve(){
   cin>>n;
   rec(0);


    vector<vector<string>> ansstr;
     for(int i=0;i<allSol.size();i++){
       vector<string> sol;
       for(int j=0;j<(int)allSol[i].size();j++){
            string row;
            for(int k=0;k<n;k++){
                row+='.';
            }
            int col = allSol[i][j];
            row[col] = 'Q';

            sol.push_back(row);
       }
       ansstr.push_back(sol);
   }

   for(int i=0;i<ansstr.size();i++){
       for(int j=0;j<(int)ansstr[i].size();j++){
           cout<<ansstr[i][j]<<endl;
       }
       cout<<endl;
       cout<<endl;
   }
   cout<<endl;
    cout<<ans<<endl;

    
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int _;cin>>_;
    // string temp;
    // getline(cin,temp);
    // while(_--)
    solve();

}