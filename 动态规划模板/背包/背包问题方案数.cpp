#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1110

#define int long long 
int mod=1e9+7;
int c[N],f[N];
signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=m;i++)c[i]=1;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        for(int j=m;j>=a;j--){
            if(f[j-a]+b>f[j]) {
                f[j]=f[j-a]+b;
                c[j]=c[j-a];
            }
            else if(f[j-a]+b==f[j]){
                c[j]=(c[j]+c[j-a])%mod;
            }
        }
    }
    cout<<c[m]<<endl;
}