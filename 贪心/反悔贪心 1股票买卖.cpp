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
    int n;
    cin>>n;
    int ans=0;
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
    	if(!q.empty()&&a[i]>q.top()) {
    		ans+=a[i]-q.top();
    		q.pop();
    		q.push(a[i]);
		}
		q.push(a[i]);
	}
	cout<<ans<<endl;
}
