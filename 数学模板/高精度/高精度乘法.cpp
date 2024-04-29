#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 3000010
int a[N],b[N],c[N];
int la,lb,lc;
void mul(int a[],int b[],int c[]){
	for(int i=0;i<la;i++){
		for(int j=0;j<lb;j++){
			c[i+j]+=a[i]*b[j];
			c[i+1+j]+=c[i+j]/10;
			c[i+j]%=10;
		}
	}
	while(lc&&c[lc]==0) lc--;
}
signed main(){
   string s,t;
   cin>>s>>t;
   la=s.size(),lb=t.size(),lc=la+lb;
   for(int i=la-1;i>=0;i--) a[la-1-i]=s[i]-'0';
   for(int i=lb-1;i>=0;i--) b[lb-1-i]=t[i]-'0';
   mul(a,b,c);
   for(int i=lc;i>=0;i--) cout<<c[i];
}
