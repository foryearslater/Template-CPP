/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
        {
            return false;
        }
        int target = sum / 2;
        vector<bool> dp(target + 10, false);
        dp[0] = true;
        for (auto x : nums)
        {
            for (int j = target; j >= x; j--)
            {
                dp[j] = dp[j] || dp[j - x];
            }
        }
        return dp[target];
    }
};
// @lc code=end
