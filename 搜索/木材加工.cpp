#include <bits/stdc++.h>
using namespace std;
#define endl '\n'    
#define int long long
typedef pair<int,int>pii;
#define N 300100
int a[N],b[N];
int n,k;
bool check(int x){
    int s=0;
    for(int i=0;i<n;i++){
        s+=a[i]/x;
    }
    return s<k;
}
signed main(){
   
    cin>>n>>k;
    int l=1,r=1e9;
    int sum=0;
    for(int i=0;i<n;i++) cin>>a[i],sum+=a[i];
    if(sum<k) 
	{
		cout<<0<<endl;
		return 0;
	}
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<r<<endl;
}