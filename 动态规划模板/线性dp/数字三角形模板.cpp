#include <bits/stdc++.h>
using namespace std;

#define long long int
#define N 1000
int a[N][N],f[N][N];
int p[N][N];//存储路径
int d[N];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=i;j++) 
    	cin>>a[i][j];
	}
	//逆序
	/*
	for(int i=n;i>=1;i--){
		for(int j=1;j<=i;j++)
		{
		   	f[i][j]=max(f[i+1][j+1],f[i+1][j])+a[i][j];
			if(f[i+1][j]>f[i+1][j+1]) p[i][j]=0;
			else p[i][j]=1; 
		}
	}
	cout<<f[1][1]<<endl;
	int i=1,j=1;
	for(;i<=n-1;i++){
		cout<<a[i][j]<<"->";
		j+=p[i][j];
	}
	cout<<a[n][j]<<endl;*/
	//顺序
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++)
		f[i][j]=-0x3f3f3f3f;
	}
	f[1][1]=a[1][1];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
		    f[i][j]=max(f[i-1][j],f[i-1][j-1])+a[i][j];
		}	
	}
	int res=-0x3f3f3f3f;
	for(int i=1;i<=n;i++) res=max(res,f[n][i]);
	cout<<res<<endl;
}
