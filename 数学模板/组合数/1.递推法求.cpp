#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 3000
int mod=1e9;
int c[N][N];
void get(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
		if(j==0) c[i][j]=1;
		else c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
}
