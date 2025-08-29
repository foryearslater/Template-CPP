/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);
        for (int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int suf = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] *= suf;
            suf *= nums[i];
        }
        return ans;
    }
};
// @lc code=end
