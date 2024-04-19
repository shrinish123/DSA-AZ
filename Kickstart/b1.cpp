#include <bits/stdc++.h>
using namespace std;

int dp[50];
int n;
int arr[50];
int cap =0;

int rec(int level){
    if(level == n){
        return 0;
    }
    
    if( dp[level] != -1){
        return dp[level];
    }
    
    int ans =0;
    
    ans = rec(level+1);
    
    if(arr[level] + rec(level+1) <= cap){
         
        ans = max( ans , arr[level]+rec(level+1));
    }
    
    return dp[level] = ans;
    
}

int weightCapacity(vector<int> weights, int maxCapacity)
{
     n  = weights.size();
    for(int i=0;i<n;i++){
        arr[i] = weights[i];
    }
    cap = maxCapacity;
    memset(dp,-1,sizeof(dp));
    return rec(0);
}

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  vector<int> weights(n);
  
  for (int i = 0; i < n; i++)
  {
    cin >> weights[i];
  }
  
  int maxCapacity;
  cin >> maxCapacity;
  cout << weightCapacity(weights, maxCapacity) << "\n";
}