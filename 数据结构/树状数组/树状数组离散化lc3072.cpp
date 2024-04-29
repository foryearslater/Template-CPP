#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int, int> pii;
#define N 300100
int a[N], b[N];
int tr1[N], tr2[N];
int n;
vector<int> all;
int lowbit(int x)
{
    return x & -x;
}
void add(int x, int tr[])
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        tr[i] += 1;
    }
}
int sum(int x, int tr[])
{
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        res += tr[i];
    }
    return res;
}
// 离散化数的下标
int find(int x)
{
    return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums;
    all=nums;
     for(int i=1;i<=n;i++) tr1[i]=tr2[i]=0;
     // 排序去重
     sort(all.begin(), all.end());
     all.erase(unique(all.begin(), all.end()), all.end());
     vector<int> a, b;
     // 添加，树状数组里存放的是数对应离散化的下标
     a.push_back(nums[0]), add(find(nums[0]), tr1);
     b.push_back(nums[1]), add(find(nums[1]), tr2);
     for (int i = 2; i < nums.size(); i++)
     {
         int x = find(nums[i]); // 计算下表
         int c = a.size() - sum(x, tr1), d = b.size() - sum(x, tr2);
         if (c > d)
             a.push_back(nums[i]), add(x, tr1);
         else if (c < d)
             b.push_back(nums[i]), add(x, tr2);
         else
         {
             if (a.size() <= b.size())
                 a.push_back(nums[i]), add(x, tr1);
             else
                 b.push_back(nums[i]), add(x, tr2);
         }
     }
     for (auto &x : b)
         a.push_back(x);
     for(auto x:a) cout<<x<<" ";
}