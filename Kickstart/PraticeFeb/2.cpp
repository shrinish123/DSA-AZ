#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'

char vowels[] = {'A', 'E', 'I', 'O', 'U','a','e','i','o','u'};


void solve(int t){

    string king;
    getline(cin,king);
    bool flag = 0;

    if( king[king.size()-1] == 'y' || king[king.size()-1] == 'Y'  ){
        cout<<"Case #"<<t<<": "<<king<<" is ruled by nobody."<<endl;
        return;
    }

    for(int i=0;i<10;i++){
        if(vowels[i] == king[king.size()-1]){
           flag =1;
        }
    }
     
     if(flag){
         cout<<"Case #"<<t<<": "<<king<<" is ruled by Alice."<<endl;
         return;
     }
     else {
          cout<<"Case #"<<t<<": "<<king<<" is ruled by Bob."<<endl;
         return;
     }

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