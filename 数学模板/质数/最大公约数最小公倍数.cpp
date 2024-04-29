#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 100000
int ans,flag;
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n;
    cin>>n>>m;
    int t=n*m;
    for(int i=1;i<=sqrt(m*n);i++)
    {
        if((n*m)%i==0&&gcd(i,(n*m)/i)==n)
        {
            ans++;
            if(i*i==n*m)  flag=1;
        }
    }
    cout<<ans*2-flag;
}
