#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 1000100
char str[N];
int ch[N][26],ne[N],cnt[N],idx;
int n;
/*
   构造trie树
   构造AC自动机
   ne[v]指v回跳边终点
   回跳边指向父节点的回跳边所指节点的儿子
   扫描主串匹配
   
*/

void insert(char *s){
	int p=0;
	for(int i=0;s[i];i++){
		int j=s[i]-'a';
		if(!ch[p][j]) ch[p][j]=++idx;
		p=ch[p][j];
	}
	cnt[p]++;
}
//建立
void build(){
	queue<int>q;
	for(int i=0;i<26;i++) {
		if(ch[0][i]) q.push(ch[0][i]);
	}
	while(q.size()){
		int u=q.front();q.pop();
		for(int i=0;i<26;i++){
			int v=ch[u][i];
			if(v) ne[v]=ch[ne[u]][i],q.push(v);
			else ch[u][i]=ch[ne[u]][i];
		}
	}
}
//查询
int query(char *s){
  int ans=0;
  for(int k=0,i=0;s[k];k++){
    i=ch[i][s[k]-'a'];
    for(int j=i;j&&~cnt[j];j=ne[j])
      ans+=cnt[j], cnt[j]=-1;
  }
  return ans;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<n; i++)
    cin>>str, insert(str);
    build();
    cin>>str;
    cout<<query(str)<<endl;
    //return 0;
}
