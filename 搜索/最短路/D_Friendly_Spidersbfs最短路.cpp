#include <bits/stdc++.h>
using namespace std;
#define endl '\n'    
#define int long long
typedef pair<int,int>pii;
#define N 600100
vector<int>g[N];
bool st[N];
int path[N];
/*
 bfs求单点到单点距离
 floyd多源最短路
 dijkstra 单点到多点
 把每个有这个因子的数放在一层
*/

bool bfs(int s,int t){
    queue<int>q;
    q.push(s);
    while(q.size()){
        int u=q.front();
        q.pop();
        if(u==t) return 1;
        if(st[u]) continue;
        st[u]=true;
        if(!g[u].size()) continue;
        for(auto x:g[u]){
            if(st[x]) continue;
            path[x]=u;
            q.push(x);
        }
    }
    return 0;
}
signed main(){
    ios::sync_with_stdio(false); 
     cin.tie(0);   
     cout.tie(0);
     int n;
     cin>>n;
     for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        for(int j=2;j*j<=x;j++){
            if(x%j==0){
                 g[i].push_back(j+n);
                 g[j+n].push_back(i);
            }
            while(x%j==0) x/=j;
        }
        if(x!=1){
            g[i].push_back(n+x);
            g[n+x].push_back(i);
        }
     }
     int S,T;
     cin>>S>>T;
     if(!bfs(S,T)) {
        cout<<-1<<endl;
        return 0;
     }
     stack<int>s;
     int now=T;
     while(1){
           if(now<=n){
              s.push(now);
           }
           if(S==now )break;
           now=path[now];
     }
     cout<<s.size()<<endl;
     while(!s.empty()){
         cout<<s.top()<<" ";
         s.pop();
     }
}