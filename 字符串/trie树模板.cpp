#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
char s[N];
int son[N][26],cnt[N],idx;

void insert(char *s){
	int p=0;
	for(int i=0;s[i];i++){
		int j=s[i]-'a';
		if(!son[p][j])son[p][j]=++idx;
		p=son[p][j];
	}
	cnt[p]++;
}

int query(char *s){
	int p=0;
	for(int i=0;s[i];i++){
		int j=s[i]-'a';
		if(!son[p][j]) return 0;
		p=son[p][j];
	}
	return cnt[p];
}
int main(){
	
} 
