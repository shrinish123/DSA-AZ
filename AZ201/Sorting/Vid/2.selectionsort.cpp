#include<bits/stdc++.h>
using namespace std;

#define int long long

int INF = 1e9;
int n;
int arr[100100];

void selectionsort(int n){

    int temp[n];

    for(int i=0;i<n;i++){

        int minind =0;

        for(int j=0;j<n;j++){
            if(arr[j] < arr[minind]){
                minind =j;
            }
        }

        temp[i] = arr[minind];
        arr[minind] = INF;
    }

    for(int i=0;i<n;i++){
        arr[i] = temp[i];
    }
}

void selectionsort(int n){

    for(int i=0;i<n-1;i++){
        int min_ind =i;

        for(int j=i+1;j<n;j++){
             if(arr[j] < arr[min_ind]){
                 min_ind = j;
             }
        }
        swap(arr[min_ind],arr[i]);

    }
}

void solve(){

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    selectionsort(n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}




signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}