#include<bits/stdc++.h>
using namespace std;



void solve(){
  string formula;
  cin>>formula;

  stack<pair<string,int>> s;

  for(int i=0;i<formula.size();i++){

      if(formula[i] == '('){

          s.push({"(",-1});

      }
      else if(formula[i] == ')') {
         
         int multiplier =0;

         while(i+1<(int)formula.size() && formula[i+1] >= '0' && formula[i+1] <= '9'){
             multiplier *= 10;
             multiplier += formula[i+1] -'0';
             i++;
         }
         if(!multiplier) multiplier=1;
         
         stack<pair<string,int>> temp;

         while(s.top().first != "("){
             temp.push({s.top().first,s.top().second * multiplier});
             s.pop();
         }
         s.pop();

         while(!temp.empty()){
             s.push(temp.top());
             temp.pop();
         }

      }
     else  if( formula[i] >=  'A' && formula[i] <= 'Z'){
          string atom;
          
          atom += formula[i];

          while(i+1<formula.size() && formula[i+1] >= 'a' && formula[i+1] <= 'z'){
               atom += formula[i+1];
               i++;
          }
          int count =0; 
           while(i+1<formula.size() && formula[i+1] >= '0' && formula[i+1] <= '9'){
               count *=10;
               count += (formula[i+1] -'0');
               i++;
           }
           if(!count ) count =1;
           s.push({atom,count});

      }

  }


  map<string,int> mp;

      while(!s.empty()){
          
          mp[s.top().first] += s.top().second;
          s.pop();
      } 

      string ans;

      for(auto it : mp){
         ans+= it.first;
         if(it.second > 1) ans+= to_string(it.second);
      }
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