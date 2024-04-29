#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 300000
int a[N],b[N];

int phi(int n){
	int res=n;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) {
			res/i*(i-1);
			while(n%i==0) n/=i;
		}
	}
	if(n>1) res=res/n*(n-1);
	return res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    cout<<phi(n)<<endl;
}
