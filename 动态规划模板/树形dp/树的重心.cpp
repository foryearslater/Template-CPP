#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 300010

vector<int>g[N];

int res;
int st[N];
int dfs(int u){
	st[u]=true;
	int size=0;//记录u最大子树节点数
	int sum=1;//记录以u为根的子树节点数
	for(auto &x:g[u]){
		if(vis[x]) continue;
		int s=dfs(x);
		size=max(size,s);
		sum+=s;
	}
	res=min(res,max(size,n-sum));
	return sum;
}
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
    	int a,b;
    	cin>>a>>b;
    	g[a].push_back(b),g[b].push_back(a);
	}
	dfs(1);
	cout<<res<<endl;
}
