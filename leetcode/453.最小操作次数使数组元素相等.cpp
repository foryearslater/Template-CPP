/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 */

// @lc code=start
class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int min = ranges::min(nums);
        int sum = accumulate(nums.begin(), nums.end(), 0LL);
        return sum - min*nums.size();
    }
};
// @lc code=end
