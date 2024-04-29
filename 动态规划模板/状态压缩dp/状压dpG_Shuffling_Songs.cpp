#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
#define int long long
typedef pair<int,int>pii;
#define N 300100

int t;
//状压dp
//剩下的songs任意摆放形成一条链数据16
//二进制枚举
//f[i][j]  表示第i个位置，最后停留的位置

string s[20][2];
int d[20][20];
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>s[i][0]>>s[i][1];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++) 
        d[i][j]=d[j][i]=0;
    }
    vector<vector<int>>f(1<<n,vector<int>(n,0));
    for(int i=0;i<n;i++) f[1<<i][i]=1;
     for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++) {
            if(s[i][0]==s[j][0]||s[i][1]==s[j][1]) d[i][j]=d[j][i]=1;
        }
    }
    int ans=0;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(f[i][j]){
                ans=max(ans,(int)__builtin_popcount(i));
                for(int k=0;k<n;k++){
                    if(((i>>k)&1)==0&&d[j][k]==1) f[i|1<<k][k]=1;
                }
            }
        }
    }
    cout<<n-ans<<endl;
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