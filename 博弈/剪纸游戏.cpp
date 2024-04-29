#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
typedef pair<int,int>pii;
#define N 3000
int a[N],b[N];
int f[N][N];
bool judge(int n){
	for(int i=2;i<=n/i;i++)
	  if(n%i==0) return false;
	  return true;
}
int sg(int a,int b){
	if(f[a][b]!=-1) return f[a][b];
	set<int>s;
	for(int i=2;i<=a-2;i++) s.insert(sg(i,b)^sg(a-i,b));
	for(int i=2;i<=b-2;i++) s.insert(sg(a,i)^sg(a,b-i));
	for(int i=0;;i++){
		if(!s.count(i)) return f[a][b]=f[b][a]=i;
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    memset(f,-1,sizeof f);
    while(cin>>n>>m){
    	if(sg(n,m)) cout<<"WIN"<<endl;
    	else cout<<"LOSE"<<endl;
	}
}
