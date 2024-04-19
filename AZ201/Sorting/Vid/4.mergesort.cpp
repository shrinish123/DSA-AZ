#include<bits/stdc++.h>
using namespace std;

#define int long long

int n;
int arr[100100];

void merge(int l,int mid,int r){

    int n1 = mid-l+1; int n2 = r-mid;
    int left[n1];
    int right[n2];

    for(int i=0;i<n1;i++){
        left[i] = arr[l+i];
    }

    for(int i=0;i<n2;i++){
        right[i] = arr[mid+1+i];
    }

    int i=0; j=0;k=0;
    while(i< n1 && j<n2  ){
        if(left[i] <= right[i]){
            arr[k] = left[i];i++ k++;
        }else{
            arr[k] = right[j];j++;k++;
        }
    }

    while(i<n1){
        arr[k] = left[i]; i++;k++;
    }

     while(j<n2){
        arr[k] = right[j]; j++;k++;
    }

}

void mergesort(int l,int r){


   if(r> l){

       int mid = (l+r)/2;

       mergesort(l,mid);
       mergesort(mid+1,r);
       merge(l,mid,r);
   }
}


void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    mergesort(0,n-1);

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