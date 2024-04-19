#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

int freq[1001000] ={0};

void solve(){
	int n,k;
    cin>>n>>k;
    int  arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   
    int ans1 = 0;
    int dist =0;

    int tail =0;
    int head =-1;

    while(tail < n){
        while(head+1 < n && (dist < k || freq[arr[head+1]] >= 1 && dist <=k)){
            head++;
            freq[arr[head]]++;
            if(freq[arr[head]] == 1) dist++;
        }
         ans1 += head-tail+1;

        if(tail<=head){
            freq[arr[tail]]--;
            if(freq[arr[tail]] == 0 )dist--;
            tail++;
        }else {
            tail++;
            head= tail-1;
        }
    }

    k =k-1;
    int ans2 =0;
    dist =0;
    tail =0;
    head =-1;

    while(tail < n){
        while(head+1 < n && (dist < k || freq[arr[head+1]] >= 1 && dist <=k)){
            head++;
            freq[arr[head]]++;
            if(freq[arr[head]] == 1) dist++;
        }
         ans2 += head-tail+1;

        if(tail<=head){
            freq[arr[tail]]--;
            if(freq[arr[tail]] == 0 )dist--;
            tail++;
        }else {
            tail++;
            head= tail-1;
        }
    }


    cout<<ans1-ans2<<endl;

}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}