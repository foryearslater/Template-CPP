#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 40
int f[N][N];
int a[N];
 int x,y,k,b;
/*
 f[i][j]表示在i个位置放置j个1组合数
 选 i-1中选j-1，不选 i-1 选j
 把数字转化为b进制数从高位到低位
 1.x==0 跳过
 2.x==1 
  第i放0 i-1 可以放k-last个1   res+=f[i-1][k-last];
  第i放1 i-1 继续枚举;
  3 x>1 第i位放res+=f[i-1][k-last];
  i 放1 res+=f[i-1][k-last-1]
  大于1 结束
 */
void init(){
	for(int i=0;i<N;i++)f[i][0]=1;
	for(int i=1;i<N;i++){
		for(int j=1;j<=i;j++){
			f[i][j]=f[i-1][j-1]+f[i-1][j];
		}
	}
}

int cal(int n){
	if(!n) return 0;
	int cnt=0;
	while(n) a[++cnt]=n%b,n/=b;
	int res=0,pre=0;
	for(int i=cnt;i>=1;i--){
		int now=a[i];
		if(now){
			res+=f[i-1][k-pre];
			if(now>1) {
				if(k-pre-1>=0) res+=f[i-1][k-pre-1];
				break;
			}
			else{//i位为1
				pre++;//更新
				if(pre>k) break;
			}
		}
		if(i==1&&pre==k) res++; //末位
	}
	return res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin>>x>>y>>k>>b;
    cout<<cal(y)-cal(x-1)<<endl;
}