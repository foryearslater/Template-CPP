#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 1010
int a[N],s[N];
int f[N][N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
    for(int len=2;len<=n;len++){
    	for(int l=1;l<=n-len+1;l++){
    		int r=l+len-1;
    		for(int j=l;j<r;j++){
    		    f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);	
			}
		}
	}
	cout<<f[1][n]<<endl;
}
