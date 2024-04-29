#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
using i64 = long long;
typedef pair<int,int>pii;
#define N 300100
int t;
i64 c[30][N];
void solve(){
    int n;
    cin>>n;
    vector<int>a(n+1),s(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
        for(int j=0;j<30;j++){
            c[j][i]=c[j][i-1]+(s[i]>>j&1);//统计前缀1个数
        }
    }
    i64 ans=0;
    for(int i=1;i<=n;i++){
        int k=29;//最高位1
        while(k>=0&&(a[i]>>k&1)==0) k--;
        if(k==-1) continue;
        ans+=(i64)(c[k][n]-c[k][i-1])*c[k][i-1];//当前位置i-n* （0-i-1）  是0
        ans += (i64)(n - i + 1 - (c[k][n] - c[k][i - 1])) * (i - c[k][i - 1]);//是1
    }
    cout<<ans<<endl;
}
int main(){  
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    cin>>t ;
    while(t--){
        solve();
    } 
    return 0 ;
}