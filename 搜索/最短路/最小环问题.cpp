#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 310
int w[N][N],d[N][N];

/*
  floyd
  ans=dij+wik+wkj;
*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    int ans=1e9;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++)
    	if(i!=j) w[i][j]=1e9;
	}
    for(int i=0;i<m;i++){
    	int a,b,c;
    	cin>>a>>b>>c;
    	w[a][b]=w[b][a]=c;
	}
	memcpy(d,w,sizeof d);
	for(int k=1; k<=n; k++){
      for(int i=1; i<k; i++)
        for(int j=i+1; j<k; j++)
         ans=min(ans,d[i][j]+w[j][k]+w[k][i]);
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
  }
  if(ans==1e9) puts("No solution.");
  else printf("%d\n",ans);
  return 0;
}
