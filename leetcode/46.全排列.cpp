/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        dfs(nums, 0, ans);
        return ans;
    }
    void dfs(vector<int> &nums, int start, vector<vector<int>> &result)
    {
        if (start == nums.size())
        {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++)
        {
            swap(nums[start], nums[i]);
            dfs(nums, start + 1, result);
            swap(nums[start], nums[i]);
        }
    }
};
// @lc code=end
