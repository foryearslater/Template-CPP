/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> sum;
        dfs(nums, 0, sum, ans);
        return ans;
    }
    void dfs(vector<int> &nums, int i, vector<int> &sum, vector<vector<int>> &ans)
    {
        ans.push_back(sum);
        for (int j = i; j < nums.size(); j++)
        {
            sum.push_back(nums[j]);
            dfs(nums, j + 1, sum, ans);
            sum.pop_back();
        }
    }
};
// @lc code=end
