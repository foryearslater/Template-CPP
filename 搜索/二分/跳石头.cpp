#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
typedef pair<int,int>pii;
#define N 300100
int a[N],b[N];
int g,n,m;

bool check(int x){
	int last=0,s=0;
	for(int i=1;i<=n+1;i++){
	     if(a[i]-a[last]<x) s++;
		 else last=i; 	
	}
	return s<=m;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>g>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[n+1]=g;
    int ans=0;
    int l=0,r=1e9;
    while(l<=r){
    	int mid=(l+r)/2;
    	if(check(mid)) ans=mid,l=mid+1;
		else  r=mid-1; 
	}
	cout<<r<<endl;
}
