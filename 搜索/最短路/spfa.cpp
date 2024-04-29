#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 300000
vector<pii>g[N];
int n,m,s;
int d[N];
bool vis[N];
int cnt[N];
queue<int>q;
bool spfa(){
	for(int i=0;i<=n;i++) d[i]=0x3f3f3f3f;
	d[1]=0;
	vis[1]=1;
	q.push(1);
    while(q.size()){
    	int t=q.front();
    	q.pop();
    	vis[t]=0;
    	for(auto x:g[t]){
    		int a=x.first,w=x.second;
    		if(d[a]>d[t]+w) {
    			d[a]=d[t]+w,cnt[a]=cnt[t]+1;//记录边数
    			if(cnt[a]>=n ) return  true;
    			if(!vis[a]) q.push(a),vis[a]=1;
			}
		}
	}
	return false;
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
}
