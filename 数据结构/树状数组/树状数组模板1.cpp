#include <bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int tr[N];
int n,m;
int a[N];
typedef long long ll;
int lowbit(int x){
	return x&-x;
}

void add(int u,int x){
	for(int i=u;i<=n;i+=lowbit(i)) tr[i]+=x;
}

int sum(int l){
	ll res=0;
	for(int i=l;i;i-=lowbit(i)) res+=tr[i];
	return res;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
//	for(int i=1;i<=n;i++) add(i,a[i]);
	while(m--){
		int op,x,b,c;
		scanf("%d%d",&op,&x);
		if(op==1) {
			scanf("%d%d",&b,&c);
			add(x,c);add(b+1,-c);
		}
		else {	
			cout<<a[x]+sum(x)<<endl;
		}
	}
}