#include <bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int n,m,s;
vector<int>e[N];
int fa[N],dep[N],son[N],sz[N],top[N];
/*
树链剖分算法
重儿子：父节点中所有儿子中子树最多的节点
轻儿子：除重儿子以外的儿子
重边：父节点+重儿子
轻边：父节点+轻儿子

fa[N] 存u的父节点
dep[N] 存u的深度
son[N] 存u的重儿子
sz[N] 存 u为根子数节点数
top[N] 存u所在重链的顶点
*/

void  dfs1(int u,int father){
	fa[u]=father,dep[u]=dep[father]+1,sz[u]=1;
	for(auto v:e[u]){
		if(v==father) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v]) son[u]=v;
	}
}

void dfs2(int u,int t){
	top[u]=t;
	if(!son[u]) return ;
	dfs2(son[u],t);
	for(auto &v:e[u]){
		if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}

int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	int a,b;
	for(int i=0;i<n-1;i++){
		scanf("%d%d",&a,&b);
		e[a].push_back(b),e[b].push_back(a);
	}
	dfs1(s,0);
	dfs2(s,0);
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",lca(a,b));
	}
}