#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 300000
vector<pii>g[N];
int n,m,s;
int d[N];
bool st[N];
int dijkstra(){
	for(int i=0;i<=n;i++) d[i]=0x3f3f3f3f;
	d[1]=0;
	for(int i=1;i<n;i++){
		int t=0;
		for(int j=1;j<=n;j++){
			if(!st[j]&&d[j]<d[t]) t=j;
		}
		
		st[t]=true;
		for(auto x:g[t]){
			int b=x.first,w=x.second;
			if(d[b]>d[t]+w) d[b]=d[t]+w;
		}
	}
    if(d[n]>0x3f3f3f3f/2)  return -1;
    return d[n];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<m;i++){
    	int a,b,c;
    	cin>>a>>b>>c;
    	g[a].push_back({b,c});
	}
	cout<<dijkstra();
}
