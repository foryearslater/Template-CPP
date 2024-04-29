#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 300010
int v[N],w[N],s[N];
int f[N];
signed main(){
   int n,m;
   cin>>n>>m;
   int cnt=0;
   for(int i=1;i<=n;i++) {
   	   int a,b,c;
   	   cin>>a>>b>>c;
   	   if(c==0){
   	      v[++cnt]=a;
		  w[cnt]=b;
		  s[cnt]=0;     	
	   }
	   else{
	   	   if(c==-1 ) c=1; 
	   	   for(int j=1;j<=c;j<<=1){
   	        v[++cnt]=j*a;
		    w[cnt]=j*b;  
			s[cnt]=1;	 
		    c-=j;
	     }
	     if(c){
         	v[++cnt]=c*a;
	     	w[cnt]=c*b;
	     	s[cnt]=1;
	     }
	 }  
   }
   
   //二维
   for(int i=1;i<=cnt;i++){
   	  if(s[i]==1){
   	  	for(int j=m;j>=v[i];j--)
   	  	    f[j]=max(f[j],f[j-v[i]]+w[i]);
    }
   	else{
   			for(int j=v[i];j<=m;j++)
   	  	    f[j]=max(f[j],f[j-v[i]]+w[i]);
	   }  
   }
   cout<<f[m]<<endl;
}
