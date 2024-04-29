#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 3000
int f[N][N];
int a[N];

/*
      模板从低位到高位预处理
      从高位到低位递推
*/
/*
类似前缀和思想
高位到低位填数分类讨论
0-ai,ai
f[i][j]表示一共i位，最高位数字位j
i k 1 2 3 4 5 6 7 ...
f[i][j]=f[i-1][j]+f[i-1][j+1]+...

*/

void init(){//预处理不下降数的个数
	for(int i=0;i<=9;i++) f[1][i]=1;
	for(int i=2;i<33;i++){
		for(int j=0;j<=9;j++){
			for(int k=j;k<=9;k++){
				f[i][j]+=f[i-1][k];
			}
		}
	}
}
int cal(int n){
	if(n==0) return 1;
	int cnt=0;
	while(n) a[++cnt]=n%10,n/=10;//每一位都存起来，从低位到高位
	int res=0,pre=0;
	for(int i=cnt;i>=1;i--){
		int now=a[i];//记录当前数
		for(int j=pre;j<now;j++) res+=f[i][j];
		if(now<pre) break;
		pre=now;
		if(i==1) res++;
	}
	return res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int l,r;
    init();
    while(cin>>l>>r)
    cout<<cal(r)-cal(l-1)<<endl;
}
