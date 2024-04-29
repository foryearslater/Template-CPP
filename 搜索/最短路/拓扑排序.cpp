#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int d[N];
int n,m;
vector<int>g[N],s;
queue<int>q;
bool  topsort()
{
    for (int i = 1; i <= n; i ++ )
    {
        if(!d[i]) q.push(i);
    }
    while(!q.empty()){
    	int t=q.front();
    	q.pop();
    	s.push_back(t);
    	for(auto x:g[t]){
    		if(--d[x]==0) q.push(x);
		}
	}
    return s.size()==n;
}
int main()
{
    cin>>n>>m;
    for (int i = 0; i < m; i ++ )
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        d[b]++;
    }
    if(topsort()) {
        for (auto x:s)
        cout << x<<" ";
    }
    else cout << -1<<endl;
}