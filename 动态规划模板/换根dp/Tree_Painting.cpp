//CF1187E
#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
#define int long long
typedef pair<int,int>pii;
#define N 300100
int n;
vector<int>g[N];
vector<int>cnt,f;
int res;
void dfs1(int u,int fa,int dep){
    cnt[u]=1;
    for(auto x:g[u]){
        if(x==fa) continue;
        dfs1(x,u,dep+1);
        f[u]+=f[x];
        cnt[u]+=cnt[x];
    }
    f[u]+=cnt[u];
}
void dfs2(int u,int fa){
    for(auto x:g[u]){
        if(x==fa) continue;
        f[x]=f[u]+n-cnt[x]*2;

        dfs2(x,u);
    }
    res=max(res,f[u]);
}
signed main(){  
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    cin>>n;
    cnt.resize(n+1);
    f.resize(n+1);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs1(1,0,0);
    dfs2(1,0);
    cout<<res<<endl;
    return 0 ;
}