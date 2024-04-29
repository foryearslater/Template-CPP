#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 300100
vector<pii>g[N];
int n,m,s;
int d[N];
bool st[N];
priority_queue<pii>q;//距离更新
int pre[N];//记录路径
int dijkstra(){
	for(int i=0;i<=n;i++) d[i]=0x3f3f3f3f;
	d[1]=0;
	q.push({0,1});
    while(q.size()){
    	auto t=q.top();
    	q.pop();
    	int u=t.second;
    	if(st[u]) continue;
    	st[u]=true;
    	for(auto x:g[u]){
    		int v=x.first,w=x.second;
    		if(d[v]>d[u]+w) d[v]=d[u]+w;
    		pre[v]=u;
    		q.push({-d[v],v});
		}
	}
    if(d[n]>0x3f3f3f3f/2)  return -1;
    return d[n];
}
void dfs(int u){
	if(u==1) {
		cout<<u<<" ";
		return ;
	}
	dfs(pre[u]);
	cout<<u<<" ";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<m;i++){
    	int a,b,c;
    	cin>>a>>b>>c;
    	g[a].push_back({b,c});
	}
	cout<<dijkstra();
}
