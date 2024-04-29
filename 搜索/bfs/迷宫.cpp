#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
const int N = 1010;
int n;
int g[N][N];
queue<pii>q;
pii pre[N][N];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
void bfs(int x,int y){
    q.push({x,y});
    memset(pre,-1,sizeof pre);
    while(!q.empty()){
        pii t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int a=t.first+dx[i],b=t.second+dy[i];
            if(a<0||b<0||a>=n||b>=n) continue;
            if(g[a][b]) continue;
            if(pre[a][b].first!=-1) continue;
            q.push({a,b});
            pre[a][b]=t;//记录路径
        }
    }
}
int main()
{
     cin>>n;
     for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
         cin>>g[i][j];
         bfs(n-1,n-1);
         pii end(0,0);
    while(1){        
        printf("%d %d\n",end.first,end.second);
        if(end.first==n-1&&end.second==n-1) break;
        end=pre[end.first][end.second];
    }
}