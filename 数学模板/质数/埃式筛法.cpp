#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 1001000
int vis[N];
int prim[N];
int cnt;
//nloglogn
void work(int n){
	for(int i=2;i<=n;i++){
		if(!vis) prim[++cnt]=i;
		for(int j=i;j<=n/i;j++){
			vis[j*i]=1;
		}
	}
}
signed main(){
    
}
