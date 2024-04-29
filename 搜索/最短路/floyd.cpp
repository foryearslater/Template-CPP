#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 3020
int d[N][N];
int p[N][N];
int n,m;
/*
动态规划
全源最短路
*/
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
			if(d[i][j]>d[i][k]+d[k][j]) {
				d[i][j]=d[i][k]+d[k][j];
				p[i][j]=k;
			}
		}
	}
}
void path(int x,int y){
	if(p[x][y]==0) return;
	int k=p[x][y];
	path(x,k);
	cout<<k<<" ";
	path(k,y);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        if(i==j) d[i][j]=0;
        else d[i][j]=0x3f3f3f3f;
    }
    while(m--){
    	 int a,b,c;
         cin>>a>>b>>c;
         d[a][b]=min(d[a][b],c);
         d[b][a]=min(d[b][a],c);
	}
	floyd();
	for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        cout<<d[i][j]<<" ";
        cout<<endl;
    }
}
