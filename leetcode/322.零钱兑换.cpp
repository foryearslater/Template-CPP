/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 10, 2e9);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; i++)
        {
            for (auto c : coins)
            {
                if (i - c < 0)
                {
                    break;
                }
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
        return dp[amount] == 2e9 ? -1 : dp[amount];
    }
};
// @lc code=end
