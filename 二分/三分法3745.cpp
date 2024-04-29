#include <bits/stdc++.h>
using namespace std;
#define endl '\n'    
#define int long long
typedef pair<int,int>pii;
#define N 300100
int a[N],b[N];
int ans;
int A,B,C;
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    cin>>A>>B>>C;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    
}