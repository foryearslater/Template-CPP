#include <bits/stdc++.h>
using namespace std;

#define long long int
#define N 100010

int a[N],f[N],b[N];
int main(){
   int n;
   cin>>n;
   for(int i=0;i<n;i++) cin>>a[i];
   /*朴素
   for(int i=0;i<n;i++){
   	  f[i]=1;
   	  for(int j=0;j<i;j++) 
   	  if(a[i]>a[j]) f[i]=max(f[i],f[j]+1);
   }
   int res=0;
   for(int i=0;i<n;i++) res=max(res,f[i]);
   cout<<res<<endl;
   */
   //二分

//    int len = 1;
//       b[0]=a[0];
//       for(int i=1;i<n;i++){
//       	  if(a[i]>b[len-1])
//       	  b[len++]=a[i];
//       	  else  {
//       	         int t=lower_bound(b,b+len-1,a[i])-b;
//    			b[t]=a[i];
//    	 }

//       }

//    cout << len << endl;
      vector<int>ans;
      for(int i=0;i<n;i++){
          auto it=upper_bound(ans.begin(),ans.end(),a[i]);
          if(it==ans.end()) ans.push_back(a[i]);
          else *it=a[i];
      }
      cout<<n-ans.size()<<endl;
}
