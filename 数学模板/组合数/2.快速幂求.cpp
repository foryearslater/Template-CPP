#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 3000
int mod=1e9+7;
int g[N],f[N];
int qmi(int a,int b,int p){
	int res=1;
	while(b){
		if(b&1) res=res*a%p;
		a=a*a %p;
		b>>=1;
	}
}
void init(){
	f[0]=g[0]=1;
	for(int i=1;i<N;i++){
		f[i]=f[i-1]*i%mod;
		g[i]=g[i-1]*qmi(i,mod-2,mod)
	}
	
}
int get(int n,int m){
	return f[n]*g[m]%mod*g[n-m]%mod;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
}
