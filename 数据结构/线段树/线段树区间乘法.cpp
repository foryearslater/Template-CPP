#include <bits/stdc++.h>
using namespace std;

#define lc u<<1
#define rc u<<1|1
#define int long long
typedef pair<int,int>pii;
#define N 300000
int w[N];
int n,p,q;
struct node{
	int l,r,sum,add,mul;
}tr[N*4];

//向上更新
void push_up(int u){
	tr[u].sum=(tr[lc].sum+tr[rc].sum)%p;
}
void cal(node &t,int m,int a){
	t.sum=(t.sum*m+(t.r-t.l+1)*a)%p;
	t.mul=t.mul*m%p;
	t.add=(t.add*m+a)%p;
}
//向下更新
void push_down(int u){
	    cal(tr[lc],tr[u].mul,tr[u].add);
	    cal(tr[rc],tr[u].mul,tr[u].add);
		tr[u].mul=1;
		tr[u].add=0;
}
//建立
void build(int u,int l,int r){
	tr[u]={l,r,w[l],0,1};
	if(l==r) return ;
	int mid=l+r>>1;
	build(lc,l,mid),build(rc,mid+1,r);
	push_up(u);
}
//更新
void update(int u,int x,int y,int m,int a){
	if(x>tr[u].r||y<tr[u].l) return ;
	if(tr[u].l>=x&&tr[u].r<=y){
		cal(tr[u],m,a);
		return ;
	}
	push_down(u);
    update(lc,x,y,m,a);
	update(rc,x,y,m,a);
	push_up(u);
}

//查询
int query(int u,int x,int y){
 if(x>tr[u].r || y<tr[u].l) return 0;
  if(x<=tr[u].l&&tr[u].r<=y) return tr[u].sum;
  push_down(u);
  return (query(lc,x,y)+query(rc,x,y))%p;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    scanf("%lld%lld%lld",&n,&q,&p);
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
	build(1,1,n);
	while(q--){
		  int op,x,y,k;
          scanf("%lld%lld%lld",&op,&x,&y);
  		  if(op==1)
          scanf("%lld",&k), update(1,x,y,k,0);
    	  else if(op==2)
          scanf("%lld",&k), update(1,x,y,1,k);
          else printf("%lld\n",query(1,x,y));
	}
}
