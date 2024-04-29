#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 100000
int a[N],b[N],c[N];
int la,lb,lc;
void add(int a[],int b[],int c[]){
	for(int i=0;i<lc;i++){
		c[i]+=a[i]+b[i];
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	if(c[lc]) lc++;
}
signed main(){
   string s,t;
   cin>>s>>t;
   la=s.size(),lb=t.size(),lc=max(la,lb);
   for(int i=la-1;i>=0;i--) a[la-1-i]=s[i]-'0';
   for(int i=lb-1;i>=0;i--) b[lb-1-i]=t[i]-'0';
   add(a,b,c);
   for(int i=lc-1;i>=0;i--) cout<<c[i];
}
