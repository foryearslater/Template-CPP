#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
typedef pair<int,int>pii;
#define N 300100
using i64 = long long;
vector<int>g[N];
int t;
int dfn[N],low[N],tot;
stack<int>s;
int scc[N],siz[N],cnt;

void tarjan(int x){
     dfn[x]=low[x]=++tot;//该节点本来就是强连通分量
     s.push(x);//入栈
     for(auto y:g[x]){
        if(!dfn[y]){
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(!scc[y]){
            low[x]=min(low[x],low[y]);
        }
     }
     if(dfn[x]==low[x]){
        ++cnt;
        while(1){
            auto y=s.top();
            s.pop();
            scc[y]=cnt;
            ++siz[cnt];
            if(y==x) break;
        }
     }
}
int main(){  
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i);
    }
   
    int ans=0;
    for(int i=1;i<=cnt;i++){
        if(siz[i]>1) ans++;
        //cout<<siz[i]<<" ";
    }
    cout<<ans<<endl;
    return 0 ;
}