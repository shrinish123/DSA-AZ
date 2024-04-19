#include<bits/stdc++.h>
using namespace std;

#define int long long 

int l,n;

void solve(){

  
  cin>>l>>n;
  priority_queue<int> pq;

  for(int i=0;i<n;i++){
      int x;
      cin>>x;
      pq.push(-x);
  }

  int cost =0;
  
  while(pq.size() >1){

      int a = -pq.top();pq.pop();
      int b = -pq.top();pq.pop();

      cost += (a+b);
      pq.push(-(a+b));
  }



  cout<<cost<<endl;

}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}