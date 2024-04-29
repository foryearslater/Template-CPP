#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
typedef pair<int,int>pii;
#define N 1100000
int f[N][2];
vector<int>g[N];
int w[N];
bool vis[N];
int n;
int a=0,b=0;
bool judge(int n){
	for(int i=2;i<=n/i;i++)
	  if(n%i==0) return false;
	  return true;
}
/*
  基环树： 一个图n点n边，只存在一个环
  比树多一条边形成环
  1.无向树
  2.外向树  每个点一个入边
  3.内向树  每个点一个出边
*/
void find(int u,int fa){
	vis[u]=true;
	for(auto x:g[u]){
		if(x==fa) {
			a=u,b=x;
			return ;
		}
		if(vis[x]) continue;
		find(x,fa); 
	}
}
int dfs(int u,int fa){
	f[u][0]=0,f[u][1]=w[u];
	for(auto x:g[u]){
		if(x==fa) continue;
		dfs(x,fa);
		f[u][0]+=max(f[x][1],f[x][0]);
		f[u][1]+=f[x][0];
	}
	return f[u][0];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
    	int b;
    	cin>>w[i]>>b;
    	g[b].push_back(i);
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
		    a=b=0;
			find(i,i);
			if(a){
			     int res1=dfs(a,a);
				 int res2=dfs(b,b);
				 sum+=max(res1,res2);	
			}
		}
	}
	cout<<sum<<endl;
}
