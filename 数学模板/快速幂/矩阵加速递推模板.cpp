#include <bits/stdc++.h>
using namespace std;

//[f[n-1],f[n]]表示矩阵
const int mod=1e9+7;
typedef long long ll;

const int N=110;
struct matrix{
	ll c[5][5];
	matrix(){	memset(c,0,sizeof c);}
}A,res;
matrix operator*(matrix &x,matrix &y){
	matrix t;//临时矩阵
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			for(int k=1;k<=3;k++){
				t.c[i][j]=(t.c[i][j]+x.c[i][k]*y.c[k][j])%mod;
			}
		}
	}
	return t;
}


//快速幂
void quickpow(ll k){
	res.c[1][1]=res.c[2][1]=res.c[3][1]=1;
	A.c[1][1]=A.c[1][3]=A.c[2][1]=A.c[3][2]=1;
	while(k){
		if(k&1) res=res*A;
		A=A*A;
		k>>=1;
	}
}

ll n;
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(res.c,0,sizeof res.c);
		memset(A.c,0,sizeof A.c);
		cin>>n;
   	    if(n<=3) {
   	      cout<<1<<endl;
		  continue;	
	   }
   	   quickpow(n-1);
   	   cout<<res.c[2][1]<<endl;
	}
   	  
}