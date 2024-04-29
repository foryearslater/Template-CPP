#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 300000
int a[N],b[N];

unordered_map<string ,int >d;
queue<string>q;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};


int bfs(string s){
	q.push(s);
	string end="123804765";
	while(q.size()){
		auto t=q.front();q.pop();
		if(t==end) return d[t];
		int k=t.find('0');
		int x=k/3,y=k%3;
		for(int i=0;i<4;i++){
			int a=x+dx[i],b=y+dy[i];
			if(a<0||a>=3||b<0||b>=3) continue;
			int dist=d[t];
			swap(t[k],t[a*3+b]);
			if(!d.count(t)) d[t]=dist+1,q.push(t);
			swap(t[k],t[a*3+b]);
		}
	}
	
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    cout<<bfs(s)<<endl;
}
