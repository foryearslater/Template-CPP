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
    int n,c;
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int l=0,r=0;
    int ans=0;
    for(int i=0;i<n;i++){
        while(l<n&&a[l]-a[i]<c) l++;
        while(r<n&&a[r]-a[i]<=c) r++;
        ans+=r-l;
    }
    cout<<ans<<endl;
     
}