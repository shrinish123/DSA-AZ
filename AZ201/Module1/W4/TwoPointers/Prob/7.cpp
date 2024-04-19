#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define end "\n"

void solve(){
	int n,k,d;
    cin>>n>>k>>d;
    int arr[n];
    int prefix[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        prefix[i] = arr[i];
        if(i) prefix[i] += prefix[i-1];
    }

   int oddcnt =0;
   multiset<int> mt;
   int ans =-1e18;
   int tail =0;int head =-1;

   while(tail < n){
       while(head+1 < n && (oddcnt < k || arr[head+1]%2 == 0 && oddcnt<=k)){
           head++;
           if(arr[head]%2)oddcnt++;

           mt.insert(prefix[head]);
       }
       
       int base = tail-1 < 0 ? 0 : prefix[tail-1];
       auto it = mt.upper_bound(base+d);
       if(it != mt.begin()){
           it--;
           ans = max(ans,*it -base);
       } 

       if(tail <= head){
           mt.erase(mt.find(prefix[tail]));
           if(arr[tail]%2)oddcnt--;
           tail++;
       }else {
           tail++;
           head =tail-1;
       }

   }
   if(ans ==-1e18){
      cout<<"IMPOSSIBLE"<<endl;
   }else {
       cout<<ans<<endl;
   }
  


}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}