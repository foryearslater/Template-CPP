#include <bits/stdc++.h>
using namespace std;
#define endl '\n'    
#define int long long
typedef pair<int,int>pii;
#define N 310
int a[N],b[N];
int f[N][N];
/*
 i表示使用前i个，匹配了前j个字母
*/
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    string t;
    cin>>t;
    int n;
    cin>>n;
 
    memset(f,0x3f,sizeof f);
    f[0][0]=0;
    for(int i=1;i<=n;i++){
         int m;
         cin>>m;
          while(m--){
          string s;
          cin>>s;
           for(int j=0;j<=t.size();j++){
                f[i][j]=min(f[i][j],f[i-1][j]);
                if(f[i-1][j]==0x3f3f3f3f) continue;
                if(t.substr(j,s.size())!=s) continue;
                f[i][j+s.size()]=min(f[i-1][j]+1,f[i][j+s.size()]);
          }
        }
    }
    if(f[n][t.size()]>=0x3f3f3f3f) cout<<-1<<endl;
    else cout<<f[n][t.size()]<<endl;
}