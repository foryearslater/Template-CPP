#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 1010
int a[N],s[N];
int f[N][N];
int g[N][N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    memset(f,0x3f,sizeof f);
    memset(g,-0x3f,sizeof g);
    for(int i=1;i<=n;i++) cin>>a[i],a[i+n]=a[i];
    for(int i=1;i<=2*n;i++) s[i]=s[i-1]+a[i],f[i][i]=0,g[i][i]=0;
    
    for(int len=2;len<=n;len++){
    	for(int l=1;l<=n*2-len+1;l++){
    		int r=l+len-1;
    		for(int j=l;j<r;j++){
    		    f[l][r]=min(f[l][r],f[l][j]+f[j+1][r]+s[r]-s[l-1]);	
    		    g[l][r]=max(g[l][r],g[l][j]+g[j+1][r]+s[r]-s[l-1]);	
			}
		}
	}
	int mi=0x3f3f3f3f,mx=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		mi=min(mi,f[i][n+i-1]);
		mx=max(mx,g[i][n+i-1]);
	}
	cout<<mi<<"\n"<<mx<<endl;
}
