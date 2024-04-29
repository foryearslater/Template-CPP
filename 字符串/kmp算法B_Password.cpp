#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
#define int long long
typedef pair<int,int>pii;
#define N 1000100
int a[N],b[N];
int t;
/*
kmp算法
求串中出现过最长的匹配的前后缀
*/
int ne[N];
int cnt[N];
string s;
signed main(){  
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    cin>>s;
    int n=s.size();
    s=' '+s;
    for(int i=2,j=0;i<=n;i++){
        while(j&&s[i]!=s[j+1])j=ne[j];
        if(s[i]==s[j+1]) j++;
        ne[i]=j;
        if(i!=n) cnt[ne[i]]++; 
    }
    int len=0;
    if(cnt[ne[n]]) len=ne[n];
    else len=ne[ne[n]];
    if(!len) cout<<"Just a legend"<<endl;
    else {
        for(int i=1;i<=len;i++ ) cout<<s[i];
    }
    return 0 ;
}