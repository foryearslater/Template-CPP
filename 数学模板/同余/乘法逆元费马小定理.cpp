#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 300000
int a[N],b[N];

/*
 同余式：a%m==b%m则两者同余
 乘法逆元：a,b互质，ax==1 mod b
 a-1
 费马小定理 ：p为质数，a,p互质 ap-1=1mod p
  a p-2* a=1 mod p
  a p-2 是逆元
*/
int qmi(int a,int b,int p){
	int res=1;
	while(b){
		if(b&1) res=res*a%p;
		a=a*a %p;
		b>>=1;
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,p;
    cin>>a>>p;
    if(a%p) {
    	cout<<qmi(a,p-2,p)<<endl;
	}
}
