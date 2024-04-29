#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
typedef long long ll;

const int N=110;
struct matrix{
	ll c[N][N];
	matrix(){	memset(c,0,sizeof c);}
}A,res;
ll n,k;

//重载乘法 
matrix operator*(matrix &x,matrix &y){
	matrix t;//临时矩阵
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				t.c[i][j]=(t.c[i][j]+x.c[i][k]*y.c[k][j])%mod;
			}
		}
	}
	return t;
}


//快速幂
void quickpow(ll k){
	for(int i=1;i<=n;i++) res.c[i][i]=1;
	while(k){
		if(k&1) res=res*A;
		A=A*A;
		k>>=1;
	}
}


int main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++)
    	   scanf("%lld",&A.c[i][j]);
	}
	quickpow(k);
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++)
    	   cout<<res.c[i][j]<<" ";
    	   cout<<endl;
	}
	
	
}