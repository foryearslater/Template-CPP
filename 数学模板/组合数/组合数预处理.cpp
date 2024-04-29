#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 300000
int a[N],b[N];
int mod=998244353;
int fact[N],infact[N];
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=a*res%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
void init(){
	fact[0]=infact[0]=1;
	for(int i=1;i<=N;i++) {
		fact[i]=fact[i]*i%mod;
		infact[i]= infact[i-1]*qmi(i,mod-2)%mod;
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
