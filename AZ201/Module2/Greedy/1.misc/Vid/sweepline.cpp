#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
#define S second
#define F first


void solve(){

	int n;
	cin>>n;
	vector<pair<int,int>> events;

  for(int i=0;i<n;i++){
	  int l,r;
	  cin>>l>>r;
	  events.push_back({l,+1});
	  events.push_back({r,-1})
  }
   
    sort(events.begin(),events.end());

	int cnt =0;
	int uni =0;
	int inter=0;

	for(int i=0;i<(int)events.size()-1;i++){

        cnt += events[i].S;
		if(cnt >0 ){
			uni += events[i+1].F - events[i].F;
		}
		if(cnt == n){
			inter += events[i+1].F - events[i].F;
		}
	}
	cout<<uni<<" "<<inter<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}

//find union and   intersection of intervals 