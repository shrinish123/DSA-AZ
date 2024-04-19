#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
#define F first
#define S second


void solve(){
   int n;
   cin>>n;
   
   vector<pair<int,pair<int,int>>> events;

   for(int i=0;i<n;i++){
       int l,r,x;
       cin>>l>>r>>x;
     events.push_back({l,{0,x}});
     events.push_back({r,{2,x}});
   }

   int q;
   cin>>q;
   for(int i=0;i<q;i++){
       int y;
       cin>>y;
       events.push_back(y,{1,i});
   }

   int ans[q];

   sort(events.begin(),events.end());
   multiset<int> mt;

   for(int i=0;i<events.size();i++){

       if(events[i].S.F == 0){
           mt.insert(events[i].S.S);
       }else if(events[i].S.F == 2){
          mt.erase(mt.find(events[i].S.S));
       }else {
          ans[events[i].S.S] = *mt.rbegin();
       }
   }

   for(int i=0;i<q;i++){
       cout<<ans<<endl;
   }
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}