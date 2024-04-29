#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define N 100010 
int n, m;
char s[N];
int p=131;
int  h[N], ans[N];

// 计算串的哈希值
int calc(char *s, int n){
  h[0] = 0;
  for(int i = 1; i <= n; i ++){
    h[i] = h[i-1]*p+s[i];
  }
  return h[n];
}

signed main(){
  cin >> n;
  for(int i=1; i<=n; i++){
    scanf("%s", s + 1);
    int m = strlen(s+1);
    ans[i] = calc(s, m);
  }
  
  sort(ans+1, ans+n+1);
  int cnt = 0;
  for(int i=1; i<=n; i++)
    if(ans[i]!=ans[i-1]) ++cnt;
  printf("%lld", cnt);
  return 0;
}