#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define ii pair<int,int>
#define F first
#define S second

string s;
int grid[7][7];
int ans = 0;

int dx[] = {1,0,-1,0};
int dy[]= {0,-1,0,1};
string dir = "DLUR";

ii st = {0,0};
ii en = {6,0};

bool check(int x,int y, int level,int i){
    if(x < 0 || x >= 7 || y< 0 || y>= 7 || grid[x][y] == 1) return 0;
    if(s[level] != '?' && s[level] != dir[i]) return 0;
    return 1;
}

void rec(int level, ii node){
    
    if(level == 48 ){
        if(node == en)
        ans++;
    //   cout<<"we found sometihng"<<endl;
      return;
    }


    char curdir= s[level];

    for(int i=0;i<4;i++){
       ii neigh = {node.F + dx[i],node.S + dy[i]};
       if(check(neigh.F,neigh.S,level,i)){

           // Placing after check
           s[level] = dir[i];
           grid[neigh.F][neigh.S]=1;

        //    cout<<neigh.F<<" "<<neigh.S<<endl;
        //    cout<<"At level "<<level<<" "<<s<<endl;


           rec(level+1,neigh);


        //    cout<<"Unplacing at level "<<level<<" with "<<neigh.F<<" , "<<neigh.S<<endl;
           if(curdir == '?')s[level] = '?';
           grid[neigh.F][neigh.S]=0;
       }
    }
}

void solve(){
   cin>>s;
   for(int i=0;i<7;i++){
       for(int j=0;j<7;j++){
          grid[i][j]  =0;
       }
   }
   grid[st.F][st.S] =1;
   rec(0,st);
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