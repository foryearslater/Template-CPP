#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 150
int c[1000][100][N];
int mod=1000;
int qmi(int a,int k){
    int res=1;
    while(k){
        if(k&1) res=res*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return res;
}
void add(int c[],int b[],int a[]){
	for(int i=0;i<N;i++){
		c[i]+=a[i]+b[i];
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
}
void get(int n,int k){
	for(int i=0;i<n;i++){
		for(int j=0;j<=i&&j<k;j++) 
		if(j==0) c[i][j][0]=1;
		else add(c[i][j],c[i-1][j],c[i-1][j-1]);
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    int t=qmi(m%mod,m);
    get(t,n);
    int i=N-1;
    while(c[t-1][n-1][i]==0) i--;
    while(i>=0) cout<<c[t-1][n-1][i--];
}
