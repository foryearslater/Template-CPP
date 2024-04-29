#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+10;
typedef pair<int,int>pii;

int dx[4]={1,2,2,1},dy[4]={2,1,-1,-2};

int n,m;
int ans;
void dfs(int a,int b){
	if(a==n&&b==m) {
		ans++;
		return ;
	}
	for(int i=0;i<4;i++){
		int x=a+dy[i],y=b+dx[i];
		if(x<0||x>n||y<0||y>m) continue;
		dfs(x,y);
	}
}
int main(){
   cin>>n>>m;
   dfs(0,0);
   cout<<ans<<endl;
}