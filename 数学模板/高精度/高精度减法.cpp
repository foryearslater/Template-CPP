#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 100000
int a[N],b[N],c[N];
int la,lb,lc;
bool cmp(int a[],int b[]){
	if(la!=lb) return la>lb;
	for(int i=la-1;i>=0;i--) {
		if(a[i]!=b[i]) return a[i]>b[i];
	}
	return true;
}
void sub(int a[],int b[],int c[]){
	for(int i=0;i<lc;i++){
		if(a[i]<b[i])
		a[i+1]--,a[i]+=10;
		c[i]=a[i]-b[i];
	}
	while(lc&&c[lc]==0) lc--;
}
signed main(){
   string s,t;
   cin>>s>>t;
   la=s.size(),lb=t.size(),lc=max(la,lb);
   for(int i=la-1;i>=0;i--) a[la-1-i]=s[i]-'0';
   for(int i=lb-1;i>=0;i--) b[lb-1-i]=t[i]-'0';
   if(!cmp(a,b)) swap(a,b) ,cout<<"-";
   sub(a,b,c);
   for(int i=lc-1;i>=0;i--) cout<<c[i];
}
