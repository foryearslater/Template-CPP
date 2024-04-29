#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 1010
int w[N],v[N];
int f[N][N];
int dp[N];
signed main(){
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
   
   //二维
   for(int i=1;i<=n;i++){
   	  for(int j=1;j<=m;j++)
   	  {     
   	  	  if(j>=v[i]) f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i]);
   	  	  else f[i][j]=f[i-1][j];
	  }
   }
   
   //一维
   for(int i=1;i<=n;i++){
   	 for(int j=m;j>=v[i];j--){
   	   dp[j]=max(dp[j],dp[j-v[i]]+w[i]); 	
	}
   }
   cout<<dp[m]<<endl;
  // cout<<f[n][m]<<endl;
   
}
