#include <bits/stdc++.h>
using namespace std;
#define endl '\n'    
#define int long long
typedef pair<int,int>pii;
#define N 55
int f[N][N][N];//长i宽j代价k


/*
    划分型dp
*/
int t;
void init(){
    for(int i=0;i<=40;i++){
        for(int j=0;j<=40;j++){
            for(int k=0;k<=50;k++){
                if(k==i*j||k==0) f[i][j][k]=0;
                else f[i][j][k]=1e9+7;
                for(int u=0;u<=k;u++){
                    for(int v=1;v<j;v++) f[i][j][k]=min(f[i][j][k],f[i][v][u]+f[i][j-v][k-u]+i*i);
                    for(int v=1;v<i;v++) f[i][j][k]=min(f[i][j][k],f[v][j][u]+f[i-v][j][k-u]+j*j);
                }
            }
        }
    }
}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    cout<<f[n][m][k]<<endl;             
}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    cin>>t ;
    init();
    while(t--){
       solve();
    }
     return 0 ; 
}