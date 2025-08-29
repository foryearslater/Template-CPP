/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution
{
public:
    int QuickSort(vector<int> &nums, int l, int r, int k)
    {
        if (l == r)
        {
            return nums[l];
        }
        int i = l - 1, j = r + 1;
        int x = nums[(l + r) / 2];
        while (i < j)
        {
            do
                i++;
            while (nums[i] < x);
            do
                j--;
            while (nums[j] > x);
            if (i < j)
            {
                swap(nums[i], nums[j]);
            }
        }
        if (k <= j)
            return QuickSort(nums, l, j, k);
        else
            return QuickSort(nums, j + 1, r, k);
    };
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();

        return QuickSort(nums, 0, n - 1, n - k );
    }
};
// @lc code=end
