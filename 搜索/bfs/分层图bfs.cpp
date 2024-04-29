#include <bits/stdc++.h>
using namespace std;
#define endl '\n'    
#define int long long
typedef pair<int,int>pii;
#define N 1010
int t;
int n,m;
char a[N][N];
int x2,y2;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

/* 
分层图bfs
*/
int d[N][N][4];

struct node{
    int x,y,flag;
};
void solve(){
  
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++) 
            d[i][j][k]=1e9;
        }
    }
    queue<node>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='S'){
                for(int k=0;k<4;k++){
                    q.push({i,j,k});
                    d[i][j][k]=0;
                }
            }
            if(a[i][j]=='T') x2=i,y2=j;
        }
    }
    while(q.size()){
        auto t=q.front();
        q.pop();
        int x=t.x,y=t.y,flag=t.flag;
        if(a[x][y]=='.'||a[x][y]=='T'||a[x][y]=='S') {
            int xx=x+dx[flag],yy=y+dy[flag];
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&a[xx][yy]!='#') {
                if(d[xx][yy][flag]>d[x][y][flag]+1) {
                    d[xx][yy][flag]=d[x][y][flag]+1;
                    q.push({xx,yy,flag});
                }
            }
        }
        else if(a[x][y]=='*'){
            for(int i=0;i<4;i++){
                if((i^flag)==2) continue;
                int xx = x + dx[i], yy = y + dy[i];
                if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] != '#')
                {
                    if (d[xx][yy][i] > d[x][y][flag] + 1){
                        q.push({xx,yy,i});
                        d[xx][yy][i] = d[x][y][flag] + 1;
                    }
                       
                }
            }
        }
    }
    int mi=1e9;
    for(int i=0;i<4;i++){
        mi= min(d[x2][y2][i],mi);
       // cout<<d[x2][y2][i]<<endl;
    }
    if(mi<8e8) cout<<mi<<endl;
    else cout<<-1<<endl;
}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    cin>>t ;
    while(t--){
       solve();
    }
     return 0 ; 
}