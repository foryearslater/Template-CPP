#include <bits/stdc++.h>
using namespace std;

/*
 cf 148 d
*/
#define int long long
typedef pair<int,int>pii;
#define N 3000
double f[N][N];
/*
    f[i][j]表示i只白鼠j只黑鼠
    f[0][1]=0 f[1][0]=1
    f[w][b]
    
    状态转移
    先手拿白鼠 f[i][j]+=i/(i+j)
    先黑后白 不动
    先黑后黑，跑白     f[i][j]+=j/(i+j)*(j-1)/(i+j-1)*i/(i+j-2)*f[i-1][j-2]
    先黑后黑，跑黑     f[i][j]+=j/(i+j)*(j-1)/(i+j-1)*(j-2)/(i+j-2)*f[i][j-3]
*/
void solve(){
    int w,b;
    cin>>w>>b;
    for(int i=1;i<=b;i++) f[0][i]=0;
    for(int i=1;i<=w;i++) f[i][0]=1;
    for(int i=1;i<=w;i++){
    	for(int j=1;j<=b;j++){
    		f[i][j]+=(double) i/(i+j);
    		if(i>=1&&j>=2) f[i][j]+=(double)j/(i+j)*(j-1)/(i+j-1)*i/(i+j-2)*f[i-1][j-2];
    	    if(j>=3)  f[i][j]+=(double)j/(i+j)*(j-1)/(i+j-1)*(j-2)/(i+j-2)*f[i][j-3];
		}
	}
	cout<<fixed<<setprecision(9);
	cout<<f[w][b]<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    t=1;
    while(t--){
        solve();
    }
}
