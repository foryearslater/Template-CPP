#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
const int N=6e3+10;
int w[N];
bool fa[N];
vector<int>g[N];

ll f[N][2];

void dfs(int u){
	f[u][1]=w[u];
	for(auto x:g[u]){
		dfs(x);
		f[u][0]+=max(f[x][0],f[x][1]);
		f[u][1]+=f[x][0];
	}
}
int main(){
    int n;
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=0;i<n-1;i++){
		int x,y;
	    scanf("%d%d",&x,&y);
		g[y].push_back(x);
		fa[x]=true;
	}
	int root=1;
	while(fa[root]) root++;
	dfs(root);
	cout<<max(f[root][0],f[root][1])<<endl;
}