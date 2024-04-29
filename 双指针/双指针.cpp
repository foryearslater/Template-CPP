#include <bits/stdc++.h>
using namespace std;
#define endl '\n'    
#define int long long
typedef pair<int,int>pii;
#define N 2000100
int a[N],b[N];

/*
双指针   尺取法
两个指针
反向扫描：i,j相反，i从头到尾，j从尾到头
同向扫描：i,j相同，都从头到尾
*/
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=a[i-1]+i;
    for(int i=n;i>=2;i--){
        if(n-a[i]>=0&&(n-a[i])%i==0){
            cout<<(n-a[i])/i+1<<" "<<(n-a[i])/i+i<<endl;
        }
    }
     
}