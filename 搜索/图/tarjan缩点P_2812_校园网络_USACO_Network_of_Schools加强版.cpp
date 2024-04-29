#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
using i64 = long long;
typedef pair<int,int>pii;
#define N 300100
vector<int>g[N];
int din[N],dout[N];//scc入度,出度
int dfn[N],low[N],scc[N];
stack<int>s;
int cnt,tot;
int siz[N];
bool st[N];
void tarjan(int x){
    dfn[x]=low[x]=++tot;
    s.push(x);
    st[x]=true;
    for(auto y:g[x]){
       if(!dfn[y]) {
          tarjan(y);
          low[x]=min(low[x],low[y]);
       }
       else if(st[y]){
          low[x]=min(low[x],low[y]);
       }
    }
    if(low[x]==dfn[x]){
        ++cnt;
        while(1){
            auto y=s.top();
            s.pop();
            st[y]=false;
            scc[y]=cnt;
            ++siz[cnt];
            if(y==x) break;
        }
    }
}
int main(){  
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        while(cin>>x){
            if(x==0 )break;
            g[i].push_back(x);
        }
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]) {
            tarjan(i);
        }
    }
    for(int x=1;x<=n;x++){
        for(auto y:g[x]){
            if(scc[x]!=scc[y]){//不在一个强连通分量之内
                din[scc[y]]++;
                dout[scc[x]]++;
            }
        }
    }
    int a=0,b=0;
    for(int i=1;i<=cnt;i++){
        if(!din[i]) a++;
        if(!dout[i]) b++;
    }
    cout<<a<<endl;
    if(cnt==1) cout<<0<<endl;
    else cout<<max(a,b)<<endl;
    return 0 ;
}