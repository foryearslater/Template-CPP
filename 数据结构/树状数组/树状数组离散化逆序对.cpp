#include <bits/stdc++.h>
using namespace std;
#define endl '\n'    
#define int long long
typedef pair<int,int>pii;
#define N 500100
struct node{
    int val,pos;
}tr[N];
int a[N];
int n;
int lowbit(int x){
    return x&-x;
}
int query(int x){
    int res=0;
    for(int i=x;i;i-=lowbit(i)) res+=a[i];
    return res;
}
void change(int x,int k){
    for(int i=x;i<=n;i+=lowbit(i)){
         a[i]+=k;
    }
}
bool cmp(node a,node b){
    if(a.val==b.val) return a.pos>b.pos;
    return a.val>b.val;
} 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>tr[i].val;
        tr[i].pos=i;
    }
    int ans=0;
    sort(tr+1,tr+1+n,cmp);
    for(int i=1;i<=n;i++){
            ans+=query(tr[i].pos-1);
            change(tr[i].pos,1);
    }    
    cout<<ans<<endl;
}