#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 500
typedef vector<int>v;
v a(N),res(N);
int p;

v mul(v &a,v &b){
	v t(N*2);
	for(int i=0;i<N;i++){
		for(int j=0;j+i<N;j++){
			t[i+j]+=a[i]*b[j];
			t[i+j+1]+=t[i+j]/10;
			t[i+j]%=10;
		}
	}
	return t;
}
void qmi(int p){
   res[0]=1,a[0]=2;
   while(p){
   if(p&1) res=mul(res,a);
      a=mul(a,a);
      p>>=1;
   } 
   res[0]--;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int p;
    cin>>p;
    cout<<(int)((p*log10(2))+1)<<endl;
    qmi(p);
	int s=0;
    for(int i=499;i>=0;i--) {
    	
    	if(s==50) s=0,cout<<endl;
    	s++;
    	cout<<res[i];
	}
}
