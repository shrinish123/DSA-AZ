#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
 map<int,int> mp;


void solve(){
	int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

   
    int ans =0;

    int tail =0;int head= -1;

    while(tail<n ){
        while(head +1 < n && ((mp.find(arr[head + 1]) == mp.end() && mp.size() < k ) || (mp.find(arr[head +1]) != mp.end()) )){
              head++;
             mp[arr[head]]++;
           
        }
        
        ans += (head-tail +1);

        if(tail <= head){
           
            mp[arr[tail]]--;
            if(mp[arr[tail]] == 0){
                mp.erase(arr[tail]);
            }
            tail++;

        }else{
            tail++;
            head = tail-1;
        }
       }	
       cout<<ans<<endl;
}


signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}