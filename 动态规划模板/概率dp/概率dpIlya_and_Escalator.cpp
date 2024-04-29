#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
#define int long long
typedef pair<int,int>pii;
#define N 3010
int a[N],b[N];
double f[N][N];
// 概率dp
// f[i][j] 表示第i个人第t秒
// 如果走电梯 从上一个转换过来 f[i-1][j-1]*p
//不走 f[i][j-1]*(1-p);
signed main(){  
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    double p;
    int n,t;
    cin>>n>>p>>t;
    cout<<fixed<<setprecision(6);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=t;j++){
            f[i][j]=1.0*f[i][j-1]*(1-p)+1.0*(f[i-1][j-1]+1)*p;
        }
    }
    cout<<f[n][t]<<endl;

    return 0 ;
}