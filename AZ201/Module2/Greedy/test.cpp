#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, t;

    cin >> t;
    while (t--)
    {
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++) cin>>arr[i];
        long long sum=0;
        for(i=1;i<n;i++)
        {
            if(arr[i]<arr[i-1])
            {
                sum+=arr[i-1]-arr[i];
            }
        }
        cout<<sum<<"\n";
    }

    return 0;
}
