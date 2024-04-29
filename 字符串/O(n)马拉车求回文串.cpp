#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 30000000
int d[N];
int z[N],p[N];
char s[N],a[N];
/*
   d[i]回文半径 以i为中心最大回文串的一半
   流程 
   计算前i-1个z函数，维护[l,r]
   1.l<r(在盒内) i对称点r-i+l 
   (1 z[r-i+l]<=r-i+1 d[i]=d[i-l+1]
   (2 z[r-i+l]<=r-i+1 d[i]=r-i+1,从r+1后枚举
   求出z[i]后，i+z[i]-1>r  l=i,r=i+z[i]-1
   
*/
  
void cal(char *s,int n){
	z[1]=1;
	for(int i=2,r=0,l;i<=n;i++){
	   if(i<=r) d[i]=min(d[r-i+l],r-i+1);
	   while(s[i-d[i]]==s[i+d[i]])d[i]++;
	   if(i+d[i]-1>r) l=i-d[i]+1,r=i+d[i]-1;
	}
}

signed main(){
     scanf("%s",a+1);
     int n=strlen(a+1);
     int k=0;
     for(int i=1;i<=n;i++) 
     s[++k]=a[i],s[++k]='#';
     n=k;
     cal(s,n);
     int mx=0;
     for(int i=1;i<=n;i++){
     	mx=max(mx,d[i]);
	 }
	 cout<<mx-1<<endl;
  return 0;
}
