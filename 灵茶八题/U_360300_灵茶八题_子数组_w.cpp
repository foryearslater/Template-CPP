#include <bits/stdc++.h>
using namespace std;
#define endl '\n'    
#define int long long
typedef pair<int,int>pii;
#define N 300100
int a[N],b[N];
/*
贡献法
第i个数 前有i+1个右边有n-i个数
总贡献是 a[i]*(i+1)*(n-i)
*/
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int sum=0;
    for(int i=0;i<n;i++){
        sum=(sum+(i+1)*(n-i)*a[i]);
    }
    cout<<sum<<endl;
     
}