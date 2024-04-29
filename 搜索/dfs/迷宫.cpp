#include <bits/stdc++.h>
using namespace std;

const int N=100;
int f[N][N];
int n,m,t;
int x,y,x2,y2;
int ans;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
void dfs(int a,int b){
     if(a==x2&&b==y2) {
    	 ans++;
    	 return ;
   	}
	    f[a][b]=1;
	    for(int i=0;i<4;i++){
	    	int ax=a+dx[i],by=b+dy[i];
	    	if(ax<1||by<1||ax>n||by>m) continue;
	    	if(f[ax][by]==1) continue;
	    	f[ax][by]=1;//锁定现场
	    	dfs(ax,by);
	    	f[ax][by]=0;//恢复现场
	    	
		}
	//	cout<<a<<" "<<b<<endl;
}
int main(){
	cin>>n>>m>>t;
	//   memset(f,0,sizeof( f));
	cin>>x>>y>>x2>>y2;
	//f[x][y]=1,f[x2][y2]=1;
	for(int i=0;i<t;i++) {
		int a,b;
		cin>>a>>b;
		f[a][b]=1;
	}
	dfs(x,y);
	cout<<ans<<endl;
}