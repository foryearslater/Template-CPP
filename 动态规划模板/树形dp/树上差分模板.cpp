#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e4+10,M=1e5+10;
vector<int>g[M];
int  dep[N],fa[N][22],power[N];
int  ans;
int n,m;
void dfs(int u,int f){
	dep[u]=dep[f]+1;
	fa[u][0]=f;
	for(int i=0;i<=20;i++){
		fa[u][i+1]=fa[fa[u][i]][i];
	}
	for(auto &x:g[u]){
		if(x!=f) dfs(x,u);
	}
}
int lca(int u,int v){
	if(dep[u]>dep[v]) swap(u,v);
	for(int i=20;i>=0;i--){
		if(dep[u]<=dep[v]-(1<<i)) v=fa[v][i];
	}
	if(u==v) return u;
	for(int i=20;i>=0;i--){
		if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	}
	return fa[u][0];
}

void dfs2(int u,int f){
	for(auto &x:g[u]){
		if(x==f) continue;
		dfs2(x,u);
		power[u]+=power[x];
	}
	ans=max(ans,power[u]);
}

int main(){
    scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int x,y;
	    scanf("%d%d",&x,&y);
		g[x].push_back(y),g[y].push_back(x);
	} 
	dfs(1,0);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		int x=lca(a,b);
		++power[a],++power[b];
		--power[x],--power[fa[x][0]];
	}   	
	dfs2(1,0);
	printf("%d\n",ans);
}