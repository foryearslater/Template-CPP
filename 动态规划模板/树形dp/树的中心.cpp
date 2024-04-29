#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 100000
int h[N],ne[N],e[N],w[N],idx;

int d1[N],d2[N],p1[N],up[N];
void add(int a,int b,int c){
	e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
int dfs_d(int u,int fa){
	d1[u]=0;//d1[u]记录从u向下最大长度
	d2[u]=0;//d2[u]记录从u向下次大长度
	for(int i=h[u];i!=-1;i=ne[i]){
		int j=e[i];
		if(j==fa) continue;
		int d=dfs_d(j,u)+w[i];
		if(d>=d1[u])d2[u]=d1[u], d1[u]=d,p1[u]=j;//最大路径从哪里下去
		else if(d>d2[u]) d2[u]=d;
	}
}
void dfs_u(int u,int fa){
	for(int i=h[u];i!=-1;i=ne[i]){
		int j=e[i];
		if(j==fa) continue;
		if(p1[u]=j) up[j]=max(up[u],d2[u])+w[i];
		else up[j]=max(up[u],d1[u])+w[i];
		dfs_u(j,u);
	}
}

signed main(){
    int n;
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=0;i<n-1;i++){
    	int a,b,c;
    	cin>>a>>b>>c;
    	add(a,b,c),add(b,a,c);
	}
	dfs_d(1,-1);
	dfs_u(1,-1);
	int res=0x3f3f3f3f;
	for(int i=1;i<=n;i++) res=min(res,max(up[i],d1[i]));
	cout<<res<<endl; 
}
