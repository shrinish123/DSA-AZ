#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"


int n,k;
string s;
string ss;
int dp[2000][2000][4];
int p[2000][2000][4];
map<char,int> mp;

bool res(int x,int y){
   return y == (x+1)%3;
}

int rec(int lvl,int cnt, int t){

    if(cnt<0){
        return -1e9;
    }

    if(lvl == n){
        return 0;
    }

    if(dp[lvl][cnt][t] != -1){
        return dp[lvl][cnt][t];
    }

    int ans =0;
    
    for(int x =0;x<3;x++){
        if( ans < res(t,mp[s[lvl]])+rec(lvl+1,cnt -((x ==t)?0:1),x)){
             ans = res(t,mp[s[lvl]])+rec(lvl+1,cnt -((x ==t)?0:1),x);
             p[lvl][cnt][t] = x;
        }
    }
   
    return dp[lvl][cnt][t] = ans;
}

void createAns(int lvl,int cnt,int t){

    if(cnt < 0){
        return;
    }

    if(lvl == n ){
        return;
    }

    if(p[lvl][cnt][t] == 0){
        ss += 'P';
       
        createAns(lvl+1,cnt -((t==0)?0:1),0);
    }else if(p[lvl][cnt][t] == 1){
         ss += 'H';
         createAns(lvl+1,cnt -((t==1)?0:1),1);
    }else {
        ss+= 'S';
        createAns(lvl+1,cnt -((t==2)?0:1),2);
    }

}

void solve(){
   cin>>n>>k;

   cin>>s;

//    //
//    / S - 1
//      P - 2
//      R -3

mp['P'] =0;
mp['H'] =1;
mp['S'] =2;

  memset(dp,-1,sizeof(dp));
  memset(p,-1,sizeof(p));
  int ans =0;
  int type =0;
        for(int i=0;i<3;i++){
           if(rec(0,k,i)> ans){
               ans = rec(0,k,i);
                type =i;
           }
        }

        createAns(0,k,type);
        cout<<ss<<endl;

}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}