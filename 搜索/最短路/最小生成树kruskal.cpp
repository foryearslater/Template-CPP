#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 300000

int p[N],ans,cnt;
struct node{
	int a,b,w;
}nodes[N];

bool cmp(node &a,node &b){
	return a.w<b.w;
}
int find(int x){
	if(x!=p[x]) p[x]=find(p[x]);
	return p[x];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,w;
		cin>>a>>b>>w;
		nodes[i]={a,b,w};
	} 
	sort(nodes,nodes+m,cmp);
	for(int i=1;i<=n;i++) p[i]=i;
	int res=0,cnt=0;
    for(int i=0;i<m;i++)
    {
        int a=nodes[i].a,b=nodes[i].b,w=nodes[i].w;
        a=find(a),b=find(b);
        if(a!=b){
            merge(a,b);
            res+=w;
            cnt++;
        }
    }
    if(cnt<n-1) cout<<"impossible"<<endl;
    else cout << res<<endl;
}
