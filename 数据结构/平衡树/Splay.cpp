#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
#define int long long
typedef pair<int,int>pii;
#define N 300100
int a[N],b[N];
struct node{
    int s[2];//左右儿子
    int p;//父亲
    int v;//节点权值
    int cnt;//权值出现次数
    int size;//子树大小、
    void init(int p1,int v1){
        p=p1,v=v1;
        cnt=size=1;
    }
}tr[N];
int root;//根节点编号
int idx;//节点个数
void push_up(int x){
    tr[x].size=tr[tr[x].s[0]].size+tr[tr[x].s[1]].size+tr[x].cnt;
}
void rotate(int x){
     int y=tr[x].p,z=tr[y].p;
     int k=tr[y].s[1]==x;
     tr[y].s[k]=tr[x].s[k^1];
     tr[tr[x].s[k^1]].p=y;
     tr[x].s[k^1]=y;
     tr[y].p=x;
     tr[z].s[tr[z].s[1]==y] =x;
     tr[x].p=z;
     push_up(y);
     push_up(x);
}
//伸展splay
void splay(int x,int k){
    while(tr[x].p!=k){
        int y=tr[x].p,z=tr[y].p;
        if(z!=k){
            (tr[y].s[0]==x)^(tr[z].s[0]==y) ?rotate(x):rotate(y);
        }
        rotate(x);
    }
    if(k==0) root=x;
}
//查找
void find(int v){
    int x=root;
    while(tr[x].s[v>tr[x].v]&&v!=tr[x].v){
        x=tr[x].s[v>tr[x].v];
    }
    splay(x,0);
}
//前驱 get_pre
int get_pre(int v){
    find(v);
    int x=root;
    if(tr[x].v<v) return x;
    x=tr[x].s[0];
    while(tr[x].s[1])x=tr[x].s[1];
    splay(x,0);
    return x;
}
//后继 get_suc
int get_suf(int v){
    find(v);
    int x = root;
    if (tr[x].v > v) return x;
    x = tr[x].s[1];
    while (tr[x].s[0])x = tr[x].s[0];
    splay(x,0);
    return x;
}
void del(int v){
    int pre=get_pre(v);
    int suf=get_suf(v);
    splay(pre,0),splay(suf,pre);
    int del=tr[suf].s[0];
    if(tr[del].cnt>1) {
        tr[del].cnt--;
        splay(del,0);
    }
    else{
        tr[suf].s[0]=0;
        splay(suf,0);
    }
}
//插入
void insert(int v){
    int x=root,p=0;
    while(x&&tr[x].v!=v) {
        p=x,x=tr[x].s[v>tr[x].v];
    }
    if(x) tr[x].cnt++;
    else{
        x=++idx;
        tr[p].s[v>tr[p].v] =x;
        tr[x].init(p,v);
    }
    splay(x,0);
}
//排名
int get_rank(int v){
    insert(v);
    int res=tr[tr[root].s[0]].size;
    del(v);
    return res;
}
//数值
int get_val(int k){
    int x=root;
    while(1){
        int y=tr[x].s[0];
        if(tr[y].size+tr[x].cnt<k){
            k-=tr[y].size+tr[x].cnt;
            x=tr[x].s[1];
        }
        else{
            if(tr[y].size>=k)x=tr[x].s[0];
            else break;
        }
    }
    splay(x,0);
    return tr[x].v;
}

signed main(){  
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    insert(-1e9),insert(1e9);
    int n;
    cin>>n;
    while(n--){
        int op,x;
        cin>>op>>x;
        if(op==1) insert(x);
        if(op==2) del(x);
        if(op==3) cout<<get_rank(x)<<endl;
        if(op==4) cout<<get_val(x+1)<<endl;
        if(op==5) cout<<tr[get_pre(x)].v<<endl;
        if(op==6) cout<<tr[get_suf(x)].v<<endl;;
    }

    return 0 ;
}

// 插入x数
// 删除x数
// 查询x数排名
// 查询排名x数值
// 求x前驱
// 求x后继