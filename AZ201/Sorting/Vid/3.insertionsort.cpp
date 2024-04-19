#include<bits/stdc++.h>
using namespace std;

#define int long long

int n;
int arr[100100];

void insertionsort(int n){

    for(int i=1;i<n;i++){
        int key = arr[i];
        int j =i-1;
        while(j>=0 && arr[j] > arr[i]){
            arr[j+1] = arr[j];
            j--;
        }
        swap(arr[i],arr[j]);
    }
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    insertionsort(n);

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