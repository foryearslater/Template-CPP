#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 1000100

int n,k;
int a[N];
deque<int>q;
signed main(){
   cin>>n>>k;
   for(int i=1;i<=n;i++) cin>>a[i];
   for(int i=1;i<=n;i++){
   	  while(q.size()&&a[q.back()]>=a[i]) q.pop_back();
   	  q.push_back(i);
   	  if(q.front()<i-k+1) q.pop_front();
   	  if(i>=k) cout<<a[q.front()]<<" ";
   }
   q.clear();
   cout<<endl;
   for(int i=1;i<=n;i++){
   	  while(q.size()&&a[q.back()]<=a[i]) q.pop_back();
   	  q.push_back(i);
   	  if(q.front()<i-k+1) q.pop_front();
   	  if(i>=k) cout<<a[q.front()]<<" ";
   }
}
