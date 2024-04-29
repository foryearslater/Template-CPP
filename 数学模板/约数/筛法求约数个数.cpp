#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 1010000
int p[N],vis[N],cnt;
int a[N];//a[i]记录i最小质因子的次数
int d[N];//d[i]记录i约数个数

/*
 piai约数有pi0,pi1,... ai+1个
 d(n)=II (ai+1)
 i为质数，a[i]=1,d[i]=2;
 线性筛法中每个数都被最小质因子筛掉
 a[m]=a[i]+1
 1.如果i被pj整除，就是最小质因子
 2.不能被整除
 a[m]=1,d[m]=d[i]*2
*/
void get(int n){
	d[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			p[++cnt]=i;
			a[i]=1,d[i]=2;
		}
		for(int j=1;i*p[j]<=n;j++){
			int m=i*p[j];
			vis[m]=1;
			if(i%p[j]==0) {
				a[m]=a[i]+1;
				d[m]=d[i]/a[m]*(a[m]+1);
				break;
			}
			else a[m]=1,d[m]=d[i]*2;
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
