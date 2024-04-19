#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'

void solve() {
    string n;
   int a,b;
   cin>>n>>a>>b;
   int pow = 1;
   int dec= 0;
   for(int i=(int)n.size()-1;i>=0;i--){
       if(n[i] >= 'A' && n[i] <= 'G'){
          dec+= (pow* (int)(n[i] - 'A' +10));
       }else{
           dec+= (pow*(int)(n[i]-'0'));
       }
        pow*=a;
   }
   
   string ans;
   while(dec>0){
       int rem = dec%b;
       if(rem > 9 ){
           char x;
           x = rem -10 + 'A';
          ans+= (x);
       }else {
           ans+=(rem+'0');
       }
       dec=dec/b;
   }
   reverse(ans.begin(),ans.end());
   cout<<ans<<endl;

}


signed main (){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;
    cin>>_t;
    string temp;
    getline(cin,temp);
    while(_t--)solve();
}