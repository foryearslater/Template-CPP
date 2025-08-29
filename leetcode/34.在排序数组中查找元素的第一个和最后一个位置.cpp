/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        auto start = lower_bound(nums.begin(), nums.end(), target);
        auto end = upper_bound(nums.begin(), nums.end(), target);
        if (start != nums.end() && *start == target)
        {
            ans.push_back(distance(nums.begin(), start));
            ans.push_back(distance(nums.begin(), end) - 1);
        }
        else
        {
            ans.push_back(-1);
            ans.push_back(-1);
        }

        return ans;
    }
};
// @lc code=end
