/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
    {
        set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            if(i>indexDiff)
            {
                s.erase(nums[i-indexDiff-1]);
            }
            auto g = s.lower_bound(nums[i] - valueDiff);
            if(g!=s.end() && *g <= nums[i] + valueDiff)
            {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};
// @lc code=end
