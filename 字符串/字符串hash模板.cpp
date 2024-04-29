#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 300000
#define P 131
int p[N],h[N];
int ans[N];
char s[N];
/*
   h[s]=s[i]*p**n-i mod M;
   哈希碰撞 p与m互为质数
   p一般为131 13331
   m最大为2 **64超过则溢出
*/

//处理hash函数前缀和
int cal(int n,char *s){
	p[0]=1,h[0]=0;
	for(int i=1;i<=n;i++) {
		p[i]=p[i-1]*P;
		h[i]=P*h[i-1]+s[i];
	}
	return h[n];
}
//s[l-r]哈希值
int get(int l,int r){
	return h[r]-h[l-1]*p[r-l+1];
}
//判断两个字串是否相同

bool substr(int l1,int r1,int l2,int r2){
	return get(l1,r1)==get(l2,r2);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
}
