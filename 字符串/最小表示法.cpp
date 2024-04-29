#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pii;
#define N 1000100
int s[N];
int n;
/*
字符串字典树最小
破环成链复制一倍
i=1,j=2，匹配长度k=0
1.相等 k++
2.>  i=i+k+1
3.<  j=j+k+1
相同 j++
*/
int cal(){
	for(int i=1;i<=n;i++) s[n+i]=s[i];
	int i=1,j=2,k=0;
	while(i<=n&&j<=n){
		for( k=0;k<n&&s[i+k]==s[j+k];k++);
		s[i+k]>s[j+k]?i=i+k+1:j=j+k+1;
		if(i==j) j++;
	//	k=0;
	}
	return min(i,j);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    int ans=cal();
    for(int i=0;i<n;i++) cout<<s[i+ans]<<" ";
}
