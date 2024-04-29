#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 300000
int  f[N];
int w[N];
/*
 转移来自之前最值
 转移
 连续m+1中有一个不选就是上道题的思想，补集思想
 f[i]=min(f[j]+w[i]  i-m<=j<=i-1
 f[0]=0;
 f[i]=sum-f[i]
*/
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    f[0]=0;
    int ans=2e18;
    deque<int>q;
    int s=0;
    m++;
    for(int i=1;i<=n;i++) cin>>w[i],s+=w[i];
	for(int i=1;i<=n;i++){
		while(q.size()&&f[q.back()]>=f[i-1]) q.pop_back();//队尾出队
		q.push_back(i-1);//入队要求的答案
		if(q.front()<i-m) q.pop_front();//队头滑出窗口
		f[i]=f[q.front()]+w[i];//维护最值
		if(i>n-m) ans=min(ans,f[i]);
	}   
	cout<<s-ans<<endl;
}