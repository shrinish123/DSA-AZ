#include<bits/stdc++.h>
using namespace std;

#define int long long

int arr[100100];
int n;

void bubblesort(){
    
    for(int i=0;i<n;i++){
        bool swapped =false;
       
       for(int j=0;j<n-i-1;j++){
           if(arr[i] > arr[j]){
               swap(arr[i],arr[j]);
               swapped =true;
           }
       }
       if(!swapped) break;
    }

}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    bubblesort();

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int _t;cin>>_t;while(_t--)
    solve();
}