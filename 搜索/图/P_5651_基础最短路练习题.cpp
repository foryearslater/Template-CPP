#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
using i64 = long long;
typedef pair<int,int>pii;
#define N 300100
vector<pii>g[N];
int t;
bool st[N];
int ans[N];
void dfs(int u){
    st[u]=true;
    for(auto x:g[u]){
       int a=x.first,b=x.second;
       if(st[a]) continue;
       ans[a]=b^ans[u];
       dfs(a);
    }
}
int main(){  
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    dfs(1);
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<(ans[x]^ans[y])<<endl;
    }
 
    return 0 ;
}