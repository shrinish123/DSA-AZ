#include<bits/stdc++.h>
using namespace std;

int n;
int ans;

vector<int> queens;

bool check(int row,int col){
	for(int prow=0;prow<row;prow++){
		int pcol = queens[prow];
		if(pcol == col || abs(prow-row)==abs(pcol-col)){
			return 0;
		}
	}
	return 1;
}

void rec(int level){ // level = row
	if(level==n){
		// current state is a solution.
		ans++;
		return;
	}
	for(int col = 0;col<n;col++){ // choices
		if(check(level,col)){ // check
			queens.push_back(col);
			rec(level+1); // go into the recursion
			queens.pop_back();
		}
	}
}

void solve(){
	cin>>n;
	ans = 0;
	rec(0);
	cout<<ans<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}