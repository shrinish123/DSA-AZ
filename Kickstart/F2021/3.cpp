#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define ii pair<int,int>
#define F first
#define S second

void solve(int t){
   int ans=0;
   
   int d,n,x;
   cin>>d>>n>>x;
   
//     if(t ==87){
//     cout<<d<<" "<<n<<" "<<x<<endl;

//    }
     
  

   vector<pair<int,ii>> days; 


     for(int i=0;i<n;i++){
        int q,l,v;
        cin>>q>>l>>v;
        //  if(t==87){
        //     cout<<q<<" "<<l<<" "<<v<<endl;
        //  }
        int rem = d - l;
        days.push_back({rem,{v,q}});
     }
     sort(days.rbegin(),days.rend());

     priority_queue<ii> pq;
     int i=0;
    
   
     while(i<days.size()){

        if(days[i].F == 0){
            break;
        }
         
        int  cur = i;
        // cout<<cur<<" ";
         
        //  if(t==87) cout << pq.size()<<endl;
          while((i < days.size()) && (days[i].F == days[cur].F)){
            pq.push({days[i].S});
            i++;
          }
         
        //  if(t==87) cout << pq.size()<<endl;
          int cnt  =0;
          while(!pq.empty() && cnt <x){
            // cout<<cnt;
              auto cu = pq.top();
              pq.pop();
              
              if(cnt + cu.S <= x){
                cnt += cu.S;
                ans += (cu.F)*(cu.S);
                // if(t ==87)cout<<","<<cu.F << pq.size() <<endl;
              }
              else{
                int left = x- cnt;
                cnt =x;
                ans += (cu.F)*(left);
                //   if(t ==87)cout<<","<<ans<<endl;
                pq.push({cu.F,cu.S - left});
              }
          }
          int daysleft =0;
          if(i-1 != days.size()-1){
           
              daysleft = days[i-1].F - days[i].F-1;
          }else{
            daysleft = days[i-1].F - 1;
          }
         


          if(daysleft> 0){


            int tot = x * daysleft;
            cnt =0;

          while(!pq.empty() && cnt <tot){

             auto cu = pq.top();
              pq.pop();
             
              if(cnt + cu.S <= tot){
                cnt += cu.S;
                  ans += (cu.F)*(cu.S);
                //    cout<<ans<<endl;
                //   if(t ==87)cout<<","<<ans<<endl;
              }
              else{
                int left = tot- cnt;
                cnt =tot;
                 ans += (cu.F)*(left);
                                //    cout<<ans<<endl;
                                //   if(t ==87)cout<<"," << ans<<endl;

                pq.push({cu.F,cu.S - left});
              }
          }

          }

          
     }
        
        


 
    //ans 
    cout<<"Case #"<<t<<": "<<ans<<endl;

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    string temp;
    getline(cin,temp);
    for(int i=1;i<=t;i++){
        solve(i);
    }
}