#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 300100
map<int,int>l,r;
int a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++) cin>>a[i];
    int st=a[1];
    for(int i=2;i<=n;i++) {
        l[a[i]] = a[i - 1];
		r[a[i - 1]] = a[i];
    }
    int q;
    cin>>q;
    while(q--){
       int a,b,c;
       cin>>c;
       if(c==1){
            cin>>a>>b;
    		int ll,rr;
			ll=a,rr=r[a];
			r[ll]=b,l[b]=ll;
    		r[b]=rr,l[rr]=b;
       }
       else {
           cin>>b;
           if(b==st) st=r[b];
           int ll=l[b],rr=r[b];
		   r[ll]=rr;
		   l[rr]=ll;
       }
    }
	vector<int>ans;
	for(int i=st;i!=0;i=r[i]){
		ans.push_back(i);
	}
	for(auto x:ans){
		cout<<x<<" ";
	}
}
