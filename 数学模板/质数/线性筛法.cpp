#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 1001000
int st[N];
int cnt;
vector<int>prime;
void work(int n){
	for(int i=2;i<=n;i++){
		if(!st[i]) prime.push_back(i);
		for(int j=1;i*prime[j]<=n;j++)
		{
			st[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}
signed main(){
    
}
