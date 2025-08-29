/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        int mx = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                {
                    dp[i] = dp[i - 1] + 2;
                    if (i - dp[i - 1] - 2 >= 0)
                    {
                        dp[i] += dp[i - dp[i - 1] - 2];
                    }
                }
                mx = max(mx, dp[i]);
            }
        }
        return mx;
    }
};
// @lc code=end
