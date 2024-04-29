#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
char g[N][N];
int n,m;
typedef pair<int, int> pii;
int dist[N][N];
queue<pii>q;

void bfs(){
    memset(dist,-1,sizeof dist);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) 
        if(g[i][j]=='1'){
            dist[i][j]=0;
            q.push({i,j});
        }
    }
    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
    while(!q.empty()){
        auto t=q.front();
        q.pop();
        //cout<<t.first<<" "<<t.second<<endl;
        for(int i=0;i<4;i++){
            int a=t.first+dx[i],b=t.second+dy[i];
            if(a<0||b<0||a>=n||b>=m) continue;
            if(dist[a][b]!=-1) continue;
            dist[a][b]=dist[t.first][t.second]+1;
            q.push({a,b});
        }
     }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++) scanf("%s",g[i]);
    bfs();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) 
        cout << dist[i][j]<<" ";
        cout<<endl;
    }
}