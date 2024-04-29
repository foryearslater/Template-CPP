#include <bits/stdc++.h>
using namespace std;

#define int long long
int p;

/*
   
*/
int qmi(int a,int k){
    int res=1;
    while(k){
        if(k&1) res=res*a%p;
        a=a*a%p;
        k>>=1;
    }
    return res;
}
int c(int a,int b){
    int res=1;
    for(int i=1,j=a;i<=b;i++,j--)
    {
        res=res*j%p;
        res=qmi(i,p-2)*res%p;
    }
    return res;
}
int lucas(int  a,int b){
    if(a<p&&b<p) return c(a,b);
    return c(a%p,b%p)*lucas(a/p,b/p)%p;
}
signed main()
{
    int t;
    cin>>t;
    while(t--){
        int  a,b;
        cin>>a>>b>>p;
        cout<<lucas(a,b)<<endl;
    }
}