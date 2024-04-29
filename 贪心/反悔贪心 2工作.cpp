#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
typedef pair<int,int>pii;
#define N 300100
pii a[N],b[N];
void solve(){

}

/*
 使用小根堆，能做先做，贪心反悔，大于堆顶放弃之前

*/ 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    priority_queue<int ,vector<int >,greater<int>>q;
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n;i++){
    	if(a[i].first==q.size()) {
    		if(a[i].second>q.top()){
    				ans-=q.top();
    		        q.pop();
    				q.push(a[i].second);
    				ans+=a[i].second;
			}
		
		}
			else {
				q.push(a[i].second);
				ans+=a[i].second;
			}
	}
	cout<<ans<<endl;
}
