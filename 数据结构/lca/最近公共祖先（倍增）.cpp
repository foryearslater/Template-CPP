#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
typedef pair<int,int>pii;
#define N 500100
int d[N],fa[N][20];
vector<int>e[N];
int n,m,s;

void dfs(int u,int father){ //树增dep,fa
	d[u]=d[father]+1;
	fa[u][0]=father;  //x上面2,4,8...的祖先fa
	for(int i=1;i<=19;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:e[u]){
		if(v!=father) dfs(v,u);
	}
}

int lca(int u,int v){ //树增lca
	if(d[u]<d[v]) swap(u,v);
	for(int i=19;i>=0;i--){
		if(d[fa[u][i]]>=d[v]) u=fa[u][i]; //x先大步后小步向上跳，直到与y同层
	}
	if(u==v) return v;
	for(int i=19;i>=0;i--){
		if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i]; 
	}
	return fa[u][0];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>s; 
	int a,b;
    for(int i=1; i<n; i++){
       cin>>a>>b;
       e[a].push_back(b); e[b].push_back(a);
   }
  dfs(s,0);
  while(m--){
  	 cin>>a>>b;
  	 cout<<lca(a,b)<<endl;
  }
}
