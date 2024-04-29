#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+100;
struct node{
	int val,pos;
}s[N];
int n,m;
int tr[N];
ll ans;
int lowbit(int x) {
	return x&-x;
}
void add(int u,int x){
	for(int i=u;i<=n;i+=lowbit(i)) tr[i]+=x;
}

ll sum(int u){
	ll res=0;
	for(int i=u;i;i-=lowbit(i)) res+=tr[i];
	return res;
}
int cmp(node a,node b){
	if(a.val==b.val) return a.pos>b.pos;
	return a.val>b.val;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&s[i].val);
		s[i].pos=i;
	}
    sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++){
		ans+=sum(s[i].pos-1);
		add(s[i].pos,1);
	}	
	cout<<ans<<endl;
}