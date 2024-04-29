#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
using i64 = long long;
typedef pair<int,int>pii;
int t;
struct SCC {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> stk;
    std::vector<int> dfn, low, bel,siz;
    int cur, cnt;
    SCC() {}
    SCC(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        siz.resize(n,0);
        bel.assign(n, -1);
        stk.clear();
        cur = cnt = 0;
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    void dfs(int x) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);
        for (auto y : adj[x]) {
            if (dfn[y] == -1) {
                dfs(y);
                low[x] = std::min(low[x], low[y]);
            } else if (bel[y] == -1) {
                low[x] = std::min(low[x], dfn[y]);
            }
        }
        if (dfn[x] == low[x]) {
            int y;
            do {
                y = stk.back();
                bel[y] = cnt;
                ++siz[cnt];
                stk.pop_back();
            } while (y != x);
            cnt++;
        }
    }
    std::vector<int> work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i);
            }
        }
        return bel;
    }
};

signed main(){  
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    int n,m;
    cin>>n>>m;
    SCC g(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        g.addEdge(a,b);
    }
    int ans=0;
    vector<int>res=g.work();
    for(int i=0;i<g.cnt;i++) {
        if(g.siz[i]>1) ans++;
    }
    cout<<ans<<endl;
    return 0 ;
}