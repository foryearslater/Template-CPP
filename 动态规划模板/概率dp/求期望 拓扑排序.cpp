#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 200100
int n,m;
int in[N],k[N];
int h[N],ne[N],e[N],w[N],out[N],idx=1;
double f[N];

void add(int a,int b,int c){
	e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void top(){
	queue<int>q;
	q.push(n);
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=h[u];i;i=ne[i]){
			int j=e[i];
			f[j]+=(f[u]+w[i])*1/k[j];
			if(--in[j]==0) q.push(j);
		}
	}
}


void solve(){
   
   cin>>n>>m;
   for(int i=0;i<m;i++){
   	  int a,b,c;
   	  cin>>a>>b>>c;
   	  add(b,a,c);
   	  in[a]++,k[a]++;
   }
   top();
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
