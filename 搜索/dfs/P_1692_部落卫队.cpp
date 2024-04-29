#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
#define int long long
typedef pair<int,int>pii;
#define N 3100
int a[N],b[N];
int t;
int ans;
bool st[N];
int pre[N];
int g[N][N];
int n,m;
//u是位置，cnt是选取人数
void dfs(int u,int cnt){
    if(u>n){///如果选取人数大于总人数并且大于最长路径，记录即可
        if(cnt>ans){
            ans=cnt;
            for(int i=1;i<=n;i++) pre[i]=st[i];
        }
        return;
    }
    bool flag=false;//判断当前位置是否存在有冲突的
    for(int i=1;i<u;i++){//没有则跳过
        if(g[u][i]==1&&st[i]){
            flag=true;
            break;
        }
    }
    //没有冲突就继续深搜
    if(!flag){
        st[u]=1;
        dfs(u+1,cnt+1);
        st[u]=0;

    }
    dfs(u+1,cnt);
}
signed main(){  
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    cin>>n>>m;
    for(int i=0;i<m;i++){
       int x,y;
       cin>>x>>y;
       g[x][y]=g[y][x]=1;
    }
    dfs(1,0);
    cout<<ans<<endl;
    for(int i=1;i<=n;i++) cout<<pre[i]<<" ";
    cout<<endl;
    return 0 ;
}