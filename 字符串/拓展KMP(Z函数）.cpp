#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 300000
int a[N],b[N];
int z[N],p[N];
char s[N],t[N];
/*
   z[i]表示s与其后缀[i,n]最长公共前缀lcp长度
   z-box
   [i,i+z[i]-1]为i匹配段
   
   流程 
   计算前i-1个z函数，维护[l,r]则s[l,r]=s[1,r-l+1]
   1.l<r(在盒内) s[i,r]=s[i-l+1,r-l+1]
   (1 z[i-l+1]<=r-i+1 z[i]=z[i-l+1]
   (2 z[i-l+1]>=r-i+1  z[i]=r-i+1,从r+1后枚举
   求出z[i]后，i+z[i]-1>r  l=i,r=i+z[i]-1
   
  */
  
void cal(char *s,int n){
	z[1]=n;
	for(int i=2,r=0,l;i<=n;i++){
	   if(i<=r) z[i]=min(z[i-l+1],r-i+1);
	   while(s[1+z[i]]==s[i+z[i]])z[i]++;
	   if(i+z[i]-1>r) l=i,r=i+z[i]-1;
	}
}

void get(int n,int m,char *s,char *t){
	for(int i=1,r=0,l;i<=m;i++){
	   if(i<=r) p[i]=min(z[i-l+1],r-i+1);
	   while(1+p[i]<=n&&i+p[i]<=m&&s[1+p[i]]==t[i+p[i]])p[i]++;
	   if(i+p[i]-1>r) l=i,r=i+p[i]-1;
	}
}
signed main(){
     scanf("%s%s",t+1,s+1);
     int m=strlen(t+1),n=strlen(s+1);
     cal(s,n);
     get(n,m,s,t);

  int ans1=0,ans2=0;
  for(int i=1; i<=n; i++)
    ans1^=i*(z[i]+1);
  for(int i=1; i<=m; i++)
    ans2^=i*(p[i]+1);
  cout<<ans1<<endl<<ans2;
  return 0;
}
