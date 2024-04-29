#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 30

int f[N][10];//i位数，最高位为j
int a[N];

void init(){
	for(int i=0;i<=9;i++) f[1][i]=1;//一位数
	for(int i=2;i<N;i++){
		for(int j=0;j<=9;j++){
			for(int k=0;k<=9;k++){
				if(abs(k-j)>=2) f[i][j]+=f[i-1][k]; 
			}
		}
	}
}

int cal(int n){
	int cnt=0;
	if(n==0) return 0;
	while(n) a[++cnt]=n%10,n/=10;
	int res=0,pre=-2;
	//答案是cnt位
	for(int i=cnt;i>=1;i--){
		int now=a[i];
		for(int j=(i==cnt);j<now;j++){
			if(abs(j-pre)>=2) res+=f[i][j]; 
		}
		if(abs(now-pre)<2) break;
		pre=now;
		if(i==1) res++;
	}
	//答案小于cnt位
	for(int i=1;i<cnt;i++){
		for(int j=1;j<=9;j++)
		res+=f[i][j];
	}
	return res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b;
	cin>>a>>b;
	init();
	cout<<cal(b)-cal(a-1);
}
