#include <bits/stdc++.h>

using namespace std;
int playlist(vector<int> &songs)
{
    //write code here
    int n = songs.size();
    for(int i=0;i<n;i++){
        songs[i] = songs[i]%60;
    }
    
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[songs[i]]++;
        int temp = -songs[i];
		mp[]
    }
    
    int ans =0;

    for(auto v : mp){
		cout<<v.first<<" "<<v.second<<endl;
        ans += v.second *(v.second -1)/2;
    }
    return ans/2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int> songs(n);
    for(int i=0;i<n;++i)
    cin>>songs[i];
    cout<<playlist(songs); 
    return 0;
}