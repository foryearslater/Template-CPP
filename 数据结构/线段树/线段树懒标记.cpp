#include <bits/stdc++.h>
using namespace std;

#define lc u<<1
#define rc u<<1|1
#define int long long
typedef pair<int,int>pii;
#define N 300000
int n,w[N];
struct node{
	int l,r,sum,add;
}tr[N*4];

//向上更新
void push_up(int u){
	tr[u].sum=tr[lc].sum+tr[rc].sum;
}
//向下更新
void push_down(int u){
	if(tr[u].add){
		tr[lc].sum+=tr[u].add*(tr[lc].r-tr[lc].l+1);
		tr[rc].sum+=tr[u].add*(tr[rc].r-tr[rc].l+1);
		tr[lc].add+=tr[u].add;
		tr[rc].add+=tr[u].add;
		tr[u].add=0;
	}
}
//建立
void build(int u,int l,int r){
	tr[u]={l,r,w[l],0};
	if(l==r) return ;
	int mid=l+r>>1;
	build(lc,l,mid),build(rc,mid+1,r);
	push_up(u);
}
//更新
void update(int u,int x,int y,int v){
	if(tr[u].l>=x&&tr[u].r<=y){
		tr[u].sum+=(tr[u].r-tr[u].l+1)*v;
		tr[u].add+=v;
		return ;
	}
	int mid=tr[u].l+tr[u].r>>1;//不覆盖则裂开
	push_down(u);
	if(x<=mid) update(lc,x,y,v);
	if(y>mid) update(rc,x,y,v);
	push_up(u);
}

//查询
int query(int u,int x,int y){
	if(tr[u].l>=x&&tr[u].r<=y){
		return tr[u].sum;
	}
	int mid=tr[u].l+tr[u].r>>1;
    push_down(u);
	int sum=0;
	if(x<=mid) sum+=query(lc,x,y);
	if(y>mid) sum+=query(rc,x,y);
	return sum; 
}
//修改

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>w[i];
	build(1,1,n);
	while(m--){
		int op;
		int x,y,z;
		cin>>op;
		if(op==1) {
			cin>>x>>y>>z;
			update(1,x,y,z);
		}
		else{
			cin>>x>>y;
			cout<<query(1,x,y)<<endl;
		}
	} 
}
