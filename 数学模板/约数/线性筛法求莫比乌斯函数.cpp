#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 1010000
int p[N],vis[N],cnt;
int m[N];
/*
        n=1 m[1]=1
        含有相同质因子 1
        不同质因子个数 -1 s
        i为质数 -1
*/
void get(int n){
    m[1]=1;
    for(int i=2;i<=n;i++){
    	if(!vis[i]){
    		p[++cnt]=i;
    		m[i]=-1;
		}
		for(int j=1;i*p[j]<=n;j++){
			int t=i*p[j];
			vis[t]=1;
			if(i%p[j]==0) {
				m[t]=0;
				break;
			}
			else m[t]=-m[i];
		}
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    get(n);
}
