#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
typedef pair<int,int>pii;
#define N 600000
int a[N],s[N];
int n,m;
int lowbit(int x){
	return x&-x;
}
void change(int x,int k){
	for(int i=x;i<=n;i+=lowbit(i)) s[i]+=k;
}
int query(int x){
	int res=0;
	for(int i=x;i>=1;i-=lowbit(i)) res+=s[i];
	return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    int op,x,y;
    for(int i=1;i<=n;i++) cin>>a[i];
	while(m--){
		cin>>op>>x;
		int k;
		if(op==1){
			cin>>y>>k;
			change(x,k),change(y+1,-k);
		}
		else cout<<a[x]+query(x)<<endl;
	} 
}
