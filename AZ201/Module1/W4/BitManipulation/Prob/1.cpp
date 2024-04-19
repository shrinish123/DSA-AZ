#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define end "\n"

void solve(){
	int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int cnt[31][n+1];

    for(int j=0;j<31;j++){
        cnt[j][0] = 0;
       for(int i=1;i<=n;i++){
          if(arr[i] &(1<<j)){
              cnt[j][i] = 0;
          }else {
              cnt[j][i] = 1;
          }
       }
    }
    int pre[31][n+1];
    for(int j=0;j<31;j++){
        pre[j][0]=0;
       for(int i=1;i<=n;i++){
          pre[j][i] = pre[j][i-1]+cnt[j][i];
       }
    }

    int q;
    cin>>q;
    while(q--){
      int x1=0,x2=0,x3 =0;
      int l,r;
      cin>>l>>r;

      for(int i=0;i<31;i++){
          int nozer = pre[i][r] - pre[i][l-1];
          int noone = r-l+1 - nozer;
          

          if(nozer > noone){
              x1 = x1 | (1<<i);
          }

          if(nozer != 0){
             x2 = x2 | (1<<i);
          }

          if(nozer < r-l+1){
              x3 = x3 | (1<<i);
          }
      }
       
        cout<<x1+x2+x3<<endl;
    }
  
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}