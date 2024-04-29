#include <bits/stdc++.h>
using namespace std;
#define endl '\n'    
#define int long long
typedef pair<int,int>pii;
#define N 1000100
int a[N],b[N];
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++ )cin>>a[i];
    map<int,int>mp;
    mp[a[0]]++;
    int cnt=1,ans=1e9;
    int l=0,r=0;
    for(int i=0,j=0;j<n;){
        if(cnt<m){
            j++;
            mp[a[j]]++;
            if(mp[a[j]]==1) cnt++;
        }
        if(cnt==m){
            if(ans>j-i+1){
                ans=j-i+1,l=i,r=j;
            }
            mp[a[i]]--;
            if(mp[a[i]]==0) cnt--;
            i++;
        }
    } 
    cout<<l+1<<" "<<r+1<<endl;
}