/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        int mid = 0;
        while (mid <= r)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[l]);
                l++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[r]);
                r--;
            }
        }
    }
};
// @lc code=end
