#include <bits/stdc++.h>
using namespace std;

#define int long long
int n,m,cnt;
int g[14];
int s[1<<14];
int f[14][1<<14];
int mod=1e8;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		int x;
    		cin>>x;
    		g[i]=(g[i]<<1) +x;//每一行二进制转化
		}
	}
	for(int i=0;i<(1<<m);i++){
		if(!(i&i>>1)) s[cnt++]=i;//合法记录
	}
	f[0][0]=1;//什么都不种
	for(int i=1;i<=n+1;i++){
		for(int a=0;a<cnt;a++){
			for(int b=0;b<cnt;b++){
				if((s[a]&g[i])==s[a]&&!(s[a]&s[b])) f[i][a]=(f[i][a]+f[i-1][b])%mod;
			}
		}
	}
	cout<<f[n+1][0]<<endl;
}
