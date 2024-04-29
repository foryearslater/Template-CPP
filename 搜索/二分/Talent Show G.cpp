#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
typedef pair<int,int>pii;
#define N 1100
int n,m;
double f[N];
int w[N],t[N];
bool check(double x){
	for(int i=1;i<=m;i++) f[i]=-1e9;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=0;j--){
	        int k=min(m,j+w[i]);
	        f[k]=max(f[k],f[j]+t[i]-x*w[i]);
		}
	}
	return f[m]>=0;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>w[i]>>t[i];
	double l=0,r=1000.0;
	double ans=0;
	while(r-l>1e-5){
		double mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid;
		else r=mid;
	} 
	cout<<(int )(ans*1000)<<endl;    
}
