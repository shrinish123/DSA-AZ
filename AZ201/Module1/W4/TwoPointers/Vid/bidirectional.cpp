#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define end "\n"

void solve(){
	int n,t;
    cin>>n>>t;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);

    int cnt =0;

    for(int j=0;j<n;j++){
        int i=0;
        int k= n-1;

        while(i<j && k>j){
            if(arr[i] + arr[j] + arr[k] == t){
               int itemp = i;
               int ktemp =k;
               while(itemp < j && arr[itemp] == arr[i] ){
                   itemp++;
               } 
               while(ktemp > j && arr[ktemp] == arr[k]){
                   ktemp--;
               }
               cnt = cnt + (itemp -i)*(k-ktemp); 
               i =itemp;
               k =ktemp;
            }else if(arr[i] + arr[j] + arr[k] < t){
                i++;
            }else {
                k--;
            }
        }
    }
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}