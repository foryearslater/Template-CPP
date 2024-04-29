#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
#define int long long
typedef pair<int,int>pii;
#define N 300100
bool st[N];
int t;
int dist[N];
vector<pii>g[N];
signed main(){  
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    for(int i=0;i<=n;i++)dist[i]=2e9;
	dist[1]=0;
    int cnt=0;
    int ans=0;
	for(int i=0;i<n;i++){
		int t=0;
		for(int j=1;j<=n;j++){
			if(!st[j]&&dist[j]<dist[t]) t=j;
		}
		st[t]=true;
        ans+=dist[t];
        if(dist[t]!=2e9) cnt++;
		for(auto x:g[t]){
			int b=x.first,w=x.second;
			if(dist[b]>+w) dist[b]=w;
		}
	}
    if(ans>2e9)  cout<<"orz"<<endl;
    else cout<<ans<<endl;
 
    return 0 ;
}