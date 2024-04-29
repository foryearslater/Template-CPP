#include <bits/stdc++.h>
using namespace std;

#define long long int
#define N 1010
int a[N],b[N];
int f[N][N]
int main(){
    int n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    a=' '+a,b=' '+b;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++)
    	if(a[i]==b[j]) f[i][j]=max(f[i][j],f[i-1][j-1]+1);
    	else f[i][j]=max(f[i-1][j],f[i][j-1]);
	}
	cout<<f[n][m]<<endl;
}
