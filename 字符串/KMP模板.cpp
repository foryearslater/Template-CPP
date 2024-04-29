#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int ne[N];
char a[N],b[N];

/*
 ne[i]表示p[1,i]中前后缀相等最大长度
 匹配失败就回到能匹配的位置
 成功就向右移动
*/
int main(){

	cin>>a+1;
	cin>>b+1;
	ne[1]=0;
	int n=strlen(a+1),m=strlen(b+1);
	//预处理ne数组 o(n)
	for(int i=2,j=0;i<=m;i++){
		while(j&&b[i]!=b[j+1]) j=ne[j];
		if(b[i]==b[j+1]) j++;
		ne[i]=j;
	}
	//进行匹配
	for(int i=1,j=0;i<=n;i++){
		while(j&&a[i]!=b[j+1]) j=ne[j];//不相等，回跳到能匹配位置
		if(a[i]==b[j+1]) j++;//右走
		if(j==m) cout<<i-m+1<<endl,j=ne[j];//匹配成功，输出匹配位置
	}
	for (int i=1;i<=m;i++)
    cout<<ne[i]<<" ";
}