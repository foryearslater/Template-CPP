#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
#define int long long
typedef pair<int,int>pii;
#define N 300100

int t;
/*
从根开始，在叶子节点重复添加1/2，共添加2个节点a，1个子节点b
每次向叶子节点添加一个顶点，叶子节点数目不变
每次向叶子节点添加2个顶点，叶子节点数目加1
按照2增长贪心
*/
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    if(c-a!=1) cout<<-1<<endl;
    else{
        if(a+b+c==1) {
            cout<<0<<endl;
            return;
        }
        int res=1,cur=1,nxt=0;
        for(int i=0;i<a+b;i++){
            if(!cur) swap(nxt,cur),res++;
            cur--,nxt++;
            if(i<a) nxt++;
        }
        cout<<res<<endl;
    }
}
signed main(){  
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    cin>>t ;
    while(t--){
        solve();
    } 
    return 0 ;
}