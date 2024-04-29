#include <bits/stdc++.h>
using namespace std;
#define endl '\n'    
#define int long long
typedef pair<int,int>pii;
#define N 300100
int a[N],b[N];
bool check(int i){

}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int n;cin>>n;   
    int l=0,r=n-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)) r=mid-1;
        else l=mid+1;
    }
   
     
}