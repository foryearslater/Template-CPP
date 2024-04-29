#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 100000

int qmi(int a,int b,int q){
   int res=1;
   while(b){
   if(b&1) res=res*a%q;
      a=a*a%q;
      b>>=1;
   } 
   return res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,q;
    cin>>a>>b>>q;
     cout<< a<< '^'<< b<< " mod "<< q<< '='<< qmi(a,b,q);
}
