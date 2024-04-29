#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e2+10;
int a[N],b[N],c[N],d[N];
int ans;
 int n;
void print(){
	ans++;
	if(ans<=3){
		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
}
void dfs(int u){
	for(int i=1;i<=n;i++){
		if(!b[i]&&!c[i+u] &&!d[n+u-i]) {
		     a[u]=i;
			 b[i]=1;
			 c[i+u]=1;
			 d[n+u-i]=1;
			 if(u==n) print();
			 else dfs(u+1);
			 b[i]=0;
			 c[i+u]=0;
			 d[n+u-i]=0;	
		}	
	}
}
int main(){
   
    cin>>n;
    dfs(1); 
	cout<<ans;   
}