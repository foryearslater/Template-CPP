/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(n);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;

        for (int i = 1; i < n; i++)
        {
            int next2 = dp[p2] * 2;
            int next3 = dp[p3] * 3;
            int next5 = dp[p5] * 5;

            dp[i] = min({next2, next3, next5});

            if (dp[i] == next2)
                p2++;
            if (dp[i] == next3)
                p3++;
            if (dp[i] == next5)
                p5++;
        }

        return dp[n - 1];
    }
};
// @lc code=end
