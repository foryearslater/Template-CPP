/*
 * @lc app=leetcode.cn id=2787 lang=cpp
 *
 * [2787] 将一个数字表示成幂的和的方案数
 */

// @lc code=start
class Solution
{
public:
    int numberOfWays(int n, int x)
    {
        int mod = 1e9+7;
        vector<int> dp(n + 1, 0);
        vector<int> a;
        for (long i = 1;; i++)
        {
            long mul = pow(i, x);
            if(mul > n)
            {
                break;
            }
            a.push_back(mul);
        }
        dp[0] = 1;
        for (auto x : a)
        {
            for (int j = n; j >= x; j--)
            {
                dp[j] = (dp[j] + dp[j - x])%mod;
            }
        }
        return dp[n];
    }
};
// @lc code=vec
