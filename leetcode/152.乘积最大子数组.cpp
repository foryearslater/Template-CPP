/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int mx = nums[0];
        int mi = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int pre = mx;
            mx = max(nums[i], max(mx * nums[i], mi * nums[i]));
            mi = min(nums[i], min(mi * nums[i], pre * nums[i]));
            res = max(res, mx);
        }
        return res;
    }
};
// @lc code=end
