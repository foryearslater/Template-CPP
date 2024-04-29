#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 200100
int h[N],ne[N],e[N],w[N],out[N],idx=1;
double f[N];

void add(int a,int b,int c){
	e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

double dfs(int u){
	if(f[u]) return f[u];
	for(int i=h[u];i;i=ne[i]){
		int j=e[i];
		f[j]=dfs(j);
		f[u]+=(f[j]+w[i])*1/out[u];
	}
	return f[u];
}


void solve(){
   int n,m;
   cin>>n>>m;
   for(int i=0;i<m;i++){
   	  int a,b,c;
   	  cin>>a>>b>>c;
   	  add(a,b,c);
   	  out[a]++;
   }
   dfs(1);
   cout<<fixed<<setprecision(2)<<f[1]<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    t=1;
    while(t--){
        solve();
    }
}
