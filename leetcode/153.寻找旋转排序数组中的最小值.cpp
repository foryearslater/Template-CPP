/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            if (nums[l] < nums[r])
            {
                return nums[l];
            }
            int mid = (l + r) / 2;
            if (nums[mid] >= nums[l])
            {
                l = mid + 1;
            }
            else
            {
                r = mid ;
            }
        }
        return nums[l];
    }
};
// @lc code=end
