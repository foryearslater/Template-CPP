#include <bits/stdc++.h>
using namespace std;

const int N=5e5+10;
vector<int>e[N];
vector<pair<int,int>>query[N];
int fa[N],vis[N],ans[N];
int n,m,s;
/*
		tarjan(塔扬算法） 离线算法 使用并查集维护祖宗节点
		e[u]存树边
		query[u]存查询
		fa[u]存父节点
		vis[u]打标记
		ans[i]存查询结果
*/

int find(int x){
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}

void tarjan(int u){
	vis[u]=true;
	for(auto &v:e[u]){
		if(!vis[v]){
			tarjan(v);
			fa[v]=u;
		}
	}
	for(auto q:query[u]){
		int a=q.first,b=q.second;
		if(vis[a]) ans[b]=find(a);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	int a,b;
	for(int i=0;i<n-1;i++)	{
		
		scanf("%d%d",&a,&b);
		e[a].push_back(b),e[b].push_back(a);
	}
	for(int i=1;i<=m;i++){
         scanf("%d%d",&a,&b);
   		 query[a].push_back({b,i});
    	 query[b].push_back({a,i});
    }
    for(int i=1;i<=N;i++) fa[i]=i;
    tarjan(s);
    for(int i=1; i<=m; i++)
    printf("%d\n",ans[i]);
  return 0;
   
}