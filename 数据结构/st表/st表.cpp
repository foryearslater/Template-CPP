#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
typedef pair<int,int>pii;
#define N 300000
int a[N],b[N];
int f[N][30];
void solve(){
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=n;i++) cin>>f[i][0];
   for(int j=1;j<=30;j++){
   	  for(int i=1;i+(1<<j)-1<=n;i++){
   	      f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);	 
	  }
   }
   while(m--){
   	  int l,r;
   	  cin>>l>>r;
   	  int k=log2(r-l+1);
   	  cout<<max(f[l][k],f[r-(1<<k)+1][k])<<endl;
   }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
