#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
using i64 = long long;
typedef pair<int,int>pii;
#define N 300100
vector<int>g[N],ne[N];
int dout[N];//scc入度,出度
int dfn[N],low[N],scc[N];
stack<int>s;
int cnt,tot;
int siz[N];
bool st[N];
int w[N],nw[N];
int dp[N];
void tarjan(int x){
    dfn[x]=low[x]=++tot;
    s.push(x);
    st[x]=true;
    for(auto y:g[x]){
       if(!dfn[y]) {
          tarjan(y);
          low[x]=min(low[x],low[y]);
       }
       else if(st[y]){
          low[x]=min(low[x],low[y]);
       }
    }
    if(low[x]==dfn[x]){
        ++cnt;
        while(1){
            auto y=s.top();
            s.pop();
            st[y]=false;
            scc[y]=cnt;
            ++siz[cnt];
            if(y==x) break;
        }
    }
}
int main(){  
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
         cin>>w[i];
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]) {
            tarjan(i);
        }
    }
    for(int x=1;x<=n;x++){
         nw[scc[x]]+=w[x];
         for(auto y:g[x]){
            if(scc[x]!=scc[y]){
                ne[scc[x]].push_back(scc[y]);
            }
         }
    }
    for(int x=cnt;x;x--){
        if(dp[x]==0){
            dp[x]=nw[x];
        }
        for(auto y:ne[x]){
            dp[y]=max(dp[y],dp[x]+nw[y]);
        }
    }
    i64 ans=0;
    for(int i=1;i<=cnt;i++){
        ans=max(ans,(i64)dp[i]);
    }
    cout<<ans<<endl;
    return 0 ;
}