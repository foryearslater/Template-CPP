#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 3000010
int a[N],c[N];
int la,lb,lc;
void div(int a[],int b,int c[]){
	int r=0;
	for(int i=la-1;i>=0;i--){
	   r=r*10+a[i];
	   c[la-1-i]=r/b;
	   r%=b;
	}
	reverse(c,c+lc);
	while(lc&&c[lc]==0) lc--;
}
signed main(){
   string s;
   cin>>s;
   int t;
   cin>>t;
   la=s.size(),lc=la;
   for(int i=la-1;i>=0;i--) a[la-1-i]=s[i]-'0';
   div(a,t,c);
   for(int i=lc;i>=0;i--) cout<<c[i];
}
