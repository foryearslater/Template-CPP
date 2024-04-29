#include <bits/stdc++.h>
using namespace std;
#define endl '\n'    
#define int long long
typedef pair<int,int>pii;
#define N 3001000
int a[N],b[N];
int m[10000100];
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
vector<int>prime;
/*
gcd(a+k,b+k)=gcd(a+k,b-a);
通过找k这个数来判断后面多少个不为1
*/
void get_prime(int n){
    for(int i=2;i<=n;i++){
        if(!m[i]) prime.push_back(i),m[i]=i;
        for(auto x:prime){
            if(i*x>n) break;
            m[i*x]=x;
            if(i%x==0) break;
        }
    }
}
int t;
void solve(){
    int x,y;
    cin>>x>>y;
    if(abs(x-y)==1) {
        cout<<-1<<endl;
        return ;
    }
    if(gcd(x,y)!=1){
        cout<<0<<endl;
        return;
    }
    int d=y-x;
    int ans=1e18;
    while(d>1){
        int p=m[d];
        d/=p;
        ans=min(ans,(p-x%p)%p);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
    get_prime(10000000);  
    cin>>t ;
    while(t--){
       solve();
    }
     return 0 ; 
}