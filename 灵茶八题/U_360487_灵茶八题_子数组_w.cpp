#include <bits/stdc++.h>
using namespace std;
#define endl '\n'    
#define int long long
typedef pair<int,int>pii;
#define N 300100
int a[N],b[N];
/*
子数组异或和的异或和：同上。更强的结论是：
    当 n 是偶数时，i+1 和 n−i 必定一奇一偶，所以 (i+1)(n−i) 是偶数，答案为 0。
    当 n是奇数时，如果 i 为奇数，那么 i+1 和 n−i 都是偶数；如果 i 为偶数，那么 i+1 和n−i 都是奇数，
    所以只有i 为偶数时 (i+1)(n−i) 才是奇数。所以，答案为所有偶数下标的 a[i] 的异或和。

*/
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    if(n%2==0){
        cout<<0<<endl;
    }
    else{
        int res=0;
       for(int i=0;i<n;i++){
        if(i%2==0)res^=a[i]; 
       }
       cout<<res<<endl;
    }
}