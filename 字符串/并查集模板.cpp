#include <bits/stdc++.h>
using namespace std;

const int N=1e4+10;
int p[N];

int find(int x){
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
void merge(int x,int y){
	int a=find(x);
	int b=find(y);
	if(a!=b) p[a]=b;
}
int main(){
	int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=N;i++) p[i]=i;
	while(m--){
		int op;
		int a,b;
		scanf("%d%d%d",&op,&a,&b); 
		if(op==1){
			merge(a,b);
		}
		else{
			if(find(a)!=find(b)) cout<<"N"<<endl;
			else cout<<"Y"<<endl;
		}
	}
}