#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
typedef pair<int,int>pii;
#define N 300100
int fa[N][22];
int dep[N];
vector<int>g[N];
int power[N];
int n,m;
int ans;
/*
   树上差分
   
   边差分：初态都为0  对x,y上的+1操作
   边权下移变成点权 dx+1,dy+1,dlca-2
   点差分： dx+1,dy+1,dlca-1,dfa[lca]-1
   自底向上计算节点差分值子树和
   
*/

int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=20;i>=0;i--){
		if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
	}
	if(u==v) return v;
	for(int i=20;i>=0;i--){
		if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	}
	return fa[u][0];
}
void dfs(int u,int f){
	dep[u]=dep[f]+1;
	fa[u][0]=f;
	for(int i=1;i<=20;i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(auto &x:g[u]){
		if(x!=f) dfs(x,u);
	}
}
void dfs2(int u,int f){
	for(auto &x:g[u]){
		if(x==f) continue;
		dfs2(x,u);
		power[u]+=power[x];
	}
	ans=max(ans,power[u]);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    int a,b;
    for(int i=0;i<n-1;i++){
    	cin>>a>>b;
    	g[a].push_back(b),g[b].push_back(a);
	}
    dfs(1,0);
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		int l=lca(a,b);
		++power[a],++power[b];
		--power[l],--power[fa[l][0]];
	}   	
	dfs2(1,0);
	cout<<ans<<endl;
}
