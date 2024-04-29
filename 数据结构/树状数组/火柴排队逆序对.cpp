#include <bits/stdc++.h>
using namespace std;
#define endl '\n'    
#define int long long
typedef pair<int,int>pii;
#define N 500100
/*
 排序不等式
 顺序积>=乱序>=逆序
 a1<b1,b1<b2
 a1b1+a2b2>a1b2>a2b1

*/
const int mod=1e8-3;
int n,ans,s[N],c[N];
struct node{
    int val,pos;
    bool operator<(node b){
        return val<b.val;
    }
}a[N],b[N];
int lowbit(int x){
    return x&-x;
}
void change(int x,int k){
    for(int i=x;i<=n;i+=lowbit(i)) s[i]+=k;
}
int query(int x){
    int res=0;
    for(int i=x;i;i-=lowbit(i))res+=s[i];
    return res; 
}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].val,a[i].pos=i;
    for(int i=1;i<=n;i++) cin>>b[i].val,b[i].pos=i;
    sort(a+1,a+1+n),sort(b+1,b+1+n);
    for(int i=1;i<=n;i++) c[a[i].pos]=b[i].pos;
    for(int i=n;i>=1;i--){
        ans=(ans+query(c[i]-1))%mod;
        change(c[i],1);
    }
    cout<<ans<<endl;
     
}