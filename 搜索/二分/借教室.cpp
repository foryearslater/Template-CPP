#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
typedef pair<int,int>pii;
#define N 1000100
int d[N],s[N],t[N],w[N],b[N];
int n,m;
bool check(int x){
	memset(b,0,sizeof b);
	for(int i=1;i<=x;i++){
	     b[s[i]]+=d[i];
	     b[t[i]+1]-=d[i];
	}
	int res=0;
	for(int i=1;i<=n;i++){
		b[i]+=b[i-1];
		if(b[i]>w[i]) return false;
	}
	return true;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++ )cin>>w[i];
    for(int i=1;i<=m;i++) cin>>d[i]>>s[i]>>t[i];
    int l=0,r=m;
    int ans=0;
    while(l<=r){
    	int mid=(l+r)/2;
    	if(check(mid)) ans=mid,l=mid+1;
    	else r=mid-1;
	}
	if(r==m){
		cout<<0<<endl;
		return 0;
	}
	cout<<"-1\n"<<r+1<<endl;
}
