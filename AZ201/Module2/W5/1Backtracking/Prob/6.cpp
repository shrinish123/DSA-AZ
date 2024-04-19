#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define F first
#define S second

map<int,int> mp;
stack<int> st;
int n;

vector<vector<int>> allSol;
vector<int> curans;

void printCurans(){
    cout<<"Printing curans below "<<endl;
    for(auto v: curans){
        cout<<v <<" ";
    }
    cout<<endl;
}
void printmap(){
      cout<<"Printing map below "<<endl;
    for(auto v : mp){
        cout<<v.F<<" "<<v.S<<endl;
    }
}

void printStack(stack<int> ss){
      cout<<"Printing stack below "<<endl;
    while(!ss.empty()){
        cout<<ss.top()<<" ";
        ss.pop();
    }
    cout<<endl;
}

void rec(int level){
  if(level == n ){
      cout<<"now pushing back at level "<<level<<" with the string as ";
      printCurans();
          printmap();
          printStack(st);
      cout<<"Size of curans is "<<curans.size()<<endl;
      allSol.push_back(curans);
      return;
  }

  for(auto v : mp){
    if(v.S != 0 ){

        //place 
        if(v.F == 1){
          st.push(1);
          curans.push_back(1);
          mp[v.F]--;
          printCurans();
          printmap();
          printStack(st);
        }else {
            if(!st.empty()){
                st.pop();
                curans.push_back(2);
                mp[v.F]--;
                printCurans();
          printmap();
          printStack(st);
            }
          
        }
        // print();
        //go to next level
        rec(level+1);

        //revert
          if(v.F == 1){
              if(!st.empty()){
                 st.pop();
                 curans.pop_back();
                 mp[v.F]++;
                 printCurans();
          printmap();
          printStack(st);
              }

         
        }else {
           
            curans.pop_back();
            mp[v.F]++;
            printCurans();
          printmap();
          printStack(st);
        }
        // print();
        
    }
  }
}

void solve(){
   cin>>n;
   for(int i=0;i<n/2;i++){
       mp[1]++;
       mp[2]++;
   }
  
   rec(0);
   for(auto v : allSol){
       for(auto ch : v){
           if(ch == 1)cout<<"(";
           else cout<<")";
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