#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'

int grid[9][9];
vector<string> A;

bool check(int i,int j,int ch){
    for(int k=0;k<9;k++){
        if(grid[i][k] == ch && k!=j) return 0;
        if(grid[k][j] == ch && k!=i) return 0; 
    }

    int basex= (i/3)*3;
    int basey= (j/3 )*3;

    for(int m = basex;m<basex+3;m++){
        for(int n=basey;n<basey+3;n++){
            if(grid[m][n] == ch && m!= i && n != j) return 0;
        }
    }

    return 1;
}

void rec(int i,int j){
    if( i== 9){
        return;
    }
    if(j==9){
        rec(i+1,0);
    }
    if(grid[i][j] !=0){
        if(!check(i,j,grid[i][j]))return ;
        rec(i,j+1);
    }
    for(int ch=1;ch<=9;ch++){
        if(check(i,j,ch)){
            grid[i][j] = ch;
            rec(i,j+1);
            grid[i][j]= 0;
        }
    }
}


void solve(){
    A.resize(9);
   for(int i=0;i<9;i++){
       cin>>A[i];
   }

   for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(A[i][j] == '.') grid[i][j] = 0;
            else grid[i][j] = A[i][j]-'0';
        }
    }

    rec(0,0);
     
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            char ch = grid[i][j];
           A[i][j] =ch;
        }
    }


     for(int i=0;i<9;i++){
       cout<<A[i]<<endl;
   }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int _;cin>>_;
    // string temp;
    // getline(cin,temp);
    // while(_--)
    solve();

}