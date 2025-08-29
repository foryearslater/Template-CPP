/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mx = 0;
        int mi = INT_MAX;
        for (auto x : prices)
        {
            mi = min(mi, x);
            mx = max(mx, x - mi);
        }
        return mx;
    }
};
// @lc code=end
