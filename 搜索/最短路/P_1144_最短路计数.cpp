#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
#define int long long
typedef pair<int,int>pii;
#define N 1000100
vector<int>g[N];
int t;
const int mod=100003;
signed main(){  
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int>cnt(n+100,0);
    vector<bool>st(n+1,false);
    priority_queue<pii>q;
    q.push({0,1});
    cnt[1]=1;
    vector<int>dist(n+1,2e9);
    dist[1]=1;
    while(q.size()){
        auto t=q.top();
        q.pop();
        if(st[t.second]) continue;
        st[t.second]=true;
        for(auto x:g[t.second]){
             if(dist[x]>dist[t.second]+1){
                cnt[x]=cnt[t.second];
                dist[x]=dist[t.second]+1;
                q.push({-dist[x],x});
             }
             else if(dist[x]==dist[t.second]+1){
                cnt[x]+=cnt[t.second];
                cnt[x]%=mod;
             }
             
        }
    }
    for(int i=1;i<=n;i++) cout<<cnt[i]<<endl;
    

    return 0 ;
}