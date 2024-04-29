#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 3000000
map<int,int>l,r;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin>>q;
    int op=-1e9-1,ed=1e9+1;
    r[op]=ed,l[ed]=op;
    while(q--){
    	int a,x,y;
    	cin>>a;
    	if(a==1){
    		cin>>x>>y;
    		int ll,rr;
    		if(y==0) ll=op,rr=r[op];
			else ll=y,rr=r[y];
			r[ll]=x,l[x]=ll;
    		r[x]=rr,l[rr]=x;
		}
		else{
			cin>>x;
			int ll=l[x],rr=r[x];
			r[ll]=rr;
			l[rr]=ll;
		}
	}
	vector<int>ans;
	for(int i=r[op];i!=ed;i=r[i]){
		ans.push_back(i);
	}
	cout<<ans.size()<<endl;
	for(auto x:ans){
		cout<<x<<" ";
	}
}
