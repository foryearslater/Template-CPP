#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
typedef pair<int,int>pii;
#define N 300000
int a[N],b[N];

/*
  a1^a2...=0先手必败
  否则必胜
*/
void solve(){
    int n;
    cin>>n;
    int res=0;
    for(int i=0;i<n;i++ )cin>>a[i],res^=a[i];
    if(res==0) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
