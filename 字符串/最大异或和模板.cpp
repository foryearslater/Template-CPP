#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,a[N];
int son[N*31][2],idx;

void insert(int x){
	int p=0;
	for(int i=30;i>=0;i--){
		int j=x>>i&1;
		if(!son[p][j]) son[p][j]=idx++;
		p=son[p][j];
	}
} 

int query(int x){
	int p=0,res=0;
	for(int i=30;i>=0;i--){
		int j=x>>i&1;
		if(!son[p][!j]) {
			res+=1<<i;
		    p=son[p][!j];
		}
		else p=son[p][j];
	}
	return res;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],insert(a[i]);
	int res=0;
	for(int i=1;i<=n;i++){
		res=max(res,query(a[i])); 
	}
	cout<<res<<endl;
} 
