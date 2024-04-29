#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
#define int long long
typedef pair<int,int>pii;
#define N 300100
bool st[N];
int t;
vector<pii>g[N];
signed main(){  
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        g[a].push_back({b,w});
    }
    vector<int>dist(n+100,INT_MAX);
    dist[s]=0;
    priority_queue<pii>q;
    q.push({0,s});
    while(q.size()){
        auto t=q.top();
        q.pop();
        int u=t.second;
        if(st[u]) continue;
    	st[u]=true;
        for(auto x:g[u]){
            int a=x.first,b=x.second;
            if(dist[a]>dist[u]+b){
                dist[a]=dist[u]+b;
            }
            q.push({-dist[a],a});
        }
    }
    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";

    return 0 ;
}