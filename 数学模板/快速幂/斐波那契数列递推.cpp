#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define int long long 
const int mod=1000000007;
struct matrix{
  int c[3][3];
  matrix(){memset(c, 0, sizeof c);}
} F, A; //F为斐波那契矩阵，A为构造矩阵

matrix operator*(matrix &a, matrix &b){ //矩阵乘法
  matrix t; //临时矩阵
  for(int i=1; i<=2; ++i)
    for(int j=1; j<=2; ++j)
      for(int k=1; k<=2; ++k)
        t.c[i][j]=(t.c[i][j]+a.c[i][k]*b.c[k][j])%mod;
  return t;
}
void quickpow(int n){ //快速幂
  F.c[1][1]=F.c[1][2]=1;
  A.c[1][1]=A.c[1][2]=A.c[2][1]=1;
  while(n){
    if(n & 1) F = F*A;
    A = A*A;
    n >>= 1;
  }
}
signed main(){
  int n; 
  cin>>n;
  if(n<=2){puts("1"); return 0;}
  quickpow(n-2);
  cout << F.c[1][1];
  return 0;
}