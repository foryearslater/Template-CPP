//树形dp模板 
#include <bits/stdc++.h>
using namespace std;




const int N=1e6+10;
int h[N],e[N],ne[N],idx,w[N];//临接矩阵进行存储 
int f[N],d[N];//表示dp 
bool st[N];//每个点的状态 
void add(int a,int b,int c){//无向图的添加 
	e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

//深搜 
void dfs(int u){
	st[u]=true;
	for(int i=h[u];i!=-1;i=ne[i]){
		int j=e[i];
		if(!st[j]){
			dfs(j);
			 f[u]=max(max(f[u],d[u]),max(d[j]+w[i],d[u]+d[j]+w[i]));
     		 d[u]=max(max(d[u],w[i]),d[j]+w[i]);
		}
	}
}
int main(){
	int n;
	cin>>n;
	int u,v,w;
	memset(h,-1,sizeof h);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	dfs(1);
	int res=INT_MIN;
    for(int i=1;i<=n;i++) res=max(res,f[i]); 
    cout<<res<<endl;
}
/*
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5+10;
int h[N],e[N],ne[N],w[N];
int cnt,n,idx;
int ans;
bool st[N];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int dfs(int u){
    st[u]=true;//标记这个点被搜索过
    int d1=0,d2=0;//d1表示u往下最长距离，d2表示次长距离
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];//取出邻接点
        if(st[j]) continue;
        int d=dfs(j)+w[i];//从u到j最大长度
        if(d>=d1) d2=d1,d1=d;
        else if(d>d2) d2=d;
    }
    ans=max(ans,d1+d2);
    return d1;
}
int main()
{
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }
    dfs(1);
    cout<<ans<<endl;
}
*/