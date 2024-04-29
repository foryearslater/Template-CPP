#include <bits/stdc++.h>
using namespace std;

#define int long long
int n,k,cnt;
int s[1<<12];
int num[1<<12];
int f[12][144][1<<12];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=0;i<(1<<n);i++){
    	if(!(i&i>>1)){
    		s[cnt++]=i;
    		for(int j=0;j<n;j++) num[i]+=(i>>j&1);
		}
	}
	f[0][0][0]=1;
	for(int i=1;i<=n+1;i++){
		for(int j=0;j<=k;j++){
			for(int a=0;a<cnt;a++){
				for(int b=0;b<cnt;b++){
					int c=num[s[a]];
					if((j>=c)&&!(s[b]&s[a])&&!(s[b]&(s[a]<<1))&&!(s[b]&(s[a]>>1)))
					f[i][j][a]+=f[i-1][j-c][b];
				}
			}
		}
	}
	cout<<f[n+1][k][0]<<endl;
}
