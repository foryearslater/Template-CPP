#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
typedef pair<int,int>pii;
#define N 300100
int fa[N][22];
int dep[N];
int mi[60];
int s[N][52];
vector<int>g[N];
int n,m;
int mod=998244353;
/*
  询问树上一些路径权值和，考虑树上前缀和，自顶向下计算前缀和s[i]
  点前缀和s[x]+s[y]-s[lca]-s[fa[lca]]
  边前缀和s[x]+s[y]-2*s[lca]
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
	for(int i=1;i<=20;i++){
			fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	
	for(auto &v:g[u]){
		if(v==f) continue;
		fa[v][0]=u;
		dep[v]=dep[u]+1;
		for(int i=1;i<=50;i++) mi[i]=mi[i-1]*dep[v]%mod;
		for(int i=1;i<=50;i++) s[v][i]=(mi[i]+s[u][i])%mod;
		dfs(v,u);
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    int a,b;
    for(int i=0;i<n-1;i++){
    	cin>>a>>b;
    	g[a].push_back(b),g[b].push_back(a);
	}
	mi[0]=1;dfs(1,0);
	cin>>m;
	for(int i=1;i<=m;i++){
		int u,v,k;
		cin>>u>>v>>k;
		int l=lca(u,v);
		int ans=(s[u][k]+s[v][k]-s[l][k]-s[fa[l][0]][k]+3*mod)%mod;
		cout<<ans<<endl;
	}
}
