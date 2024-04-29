#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 500;
int f[N];
int w[N],v[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int s;
        cin>>s;
        for(int j=1;j<=s;j++)cin>>v[j]>>w[j];
        for(int j=m;j>=1;j--){
            for(int k=0;k<=s;k++){
                  if(j>=v[k])
                  f[j]=max(f[j],f[j-v[k]]+w[k]);
            }
        }
    }
    cout<<f[m]<<endl;
}