#include <bits/stdc++.h>
using namespace std;
#define endl '\n'    
#define int long long
typedef pair<int,int>pii;
#define N 300100
int a[N],b[N];
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;   
    list<int>node;//双向链表
    for(int i=1;i<=n;i++) node.push_back(i);
    auto it=node.begin();
    while(node.size()>1){
        for(int i=1;i<m;i++) {
            it++;
            if(it==node.end()) it=node.begin();
        }
        cout<<*(it)<<" ";
        it++;
        auto nx=it;
        if(nx==node.end()) nx=node.begin();
        node.erase(--it);
        it=nx;
    }
    cout<<*it<<endl;
}