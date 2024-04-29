#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 101000
int v[N],w[N];
int f[N];
int dp[N];
signed main(){
   int n,m;
   cin>>n>>m;
   int cnt=0;
   for(int i=1;i<=n;i++) {
   	   int a,b,c;
   	   cin>>a>>b>>c;
   	   for(int j=1;j<=c;j<<=1){
   	        v[++cnt]=j*a;
			w[cnt]=j*b;  	 
			c-=j;
	  }
	  if(c){
	  	v[++cnt]=c*a;
	  	w[cnt]=c*b;
	  }
   }
   
   //二维
   for(int i=1;i<=cnt;i++){
   	  for(int j=m;j>=v[i];j--)
   	  {     
   	  	  f[j]=max(f[j],f[j-v[i]]+w[i]);
	  }
   }
   cout<<f[m]<<endl;
}
