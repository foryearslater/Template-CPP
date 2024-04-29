#include <bits/stdc++.h>
using namespace std;
const int N=2e5+100;
#define int long long 
struct node{
	int x,y; 
} a[N];

int t[N];
//归并排序
bool cmp(node a,node b){
	if(a.x==b.x ) return a.y<b.y; 
	return a.x<b.x;
}
int merge_sort(int l,int r){
	if(l>=r) return 0;
	int mid=(l+r)>>1;
	int res=merge_sort(l,mid)+merge_sort(mid+1,r);
	int k=0,i=l,j=mid+1;
	while(i<=mid&&j<=r){
		if(a[i].y<a[j].y) t[k++]=a[i++].y;
		else{
			res+=mid-i+1;
			t[k++]=a[j++].y;
		}
	}
	while(i<=mid ) t[k++] =a[i++].y;
	while(j<=r) t[k++] =a[j++].y;
	for(int i=0,j=l;j<=r;j++,i++) a[j].y=t[i];
	return res;
}
signed  main(){
	int t;
    cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
		sort(a+1,a+1+n,cmp);
		int ans=merge_sort(1,n);
		
		//for(int i=1;i<=n;i++) cout<<a[i].y<<" ";
		cout<<ans<<endl;
	}
}



/*  树状数组
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=5e5+100;
struct node{
	int val,pos;
};
int nm;
int n;
int tr[N];

int lowbit(int x) {
	return x&-x;
}
void add(int u,int x){
	for(int i=u;i<=nm;i+=lowbit(i)) tr[i]+=x;
}

int sum(int l,int r){
	int res=0;
	for(int i=r;i;i-=lowbit(i)) res+=tr[i];
	for(int i=l-1;i;i-=lowbit(i)) res-=tr[i];
	return res;
}
int cmp(node a,node b){
   return a.val<b.val;
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		map<int,int>mp;//双hash判断
		node s[n+2];
	    for(int i=1;i<=n;i++) {
		    cin>>s[i].val>>s[i].pos;
		    mp[s[i].pos]++,mp[s[i].val]++;
	    }
	    map<int,int>m;
	    int cnt=1;
	    int o=mp.size();
	    nm=o;
	    for(int i=1;i<=o+1;i++) tr[i]=0;
	    for(auto &x:mp){
	    	m[x.first]=cnt;
	    	cnt++;
		}
		
        sort(s+1,s+1+n,cmp);
	    for(int i=1;i<=n;i++){
	    	ans+=sum(m[s[i].pos]+1,cnt);
	    	add(m[s[i].pos],1);
		}
	    cout<<ans<<endl;
	}
}*/