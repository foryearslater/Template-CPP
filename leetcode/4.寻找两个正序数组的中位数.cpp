/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        int l = (n + m + 1) / 2;
        int r = (n + m + 2) / 2;
        return (findKth(nums1, 0, n - 1, nums2, 0, m - 1, l) + findKth(nums1, 0, n - 1, nums2, 0, m - 1, r)) / 2;
    }
    double findKth(vector<int> &nums1, int start1, int end1, vector<int> &nums2, int start2, int end2, int k)
    {
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        if (len1 == 0)
            return nums2[start2 + k - 1];
        if (len2 == 0)
            return nums1[start1 + k - 1];
        if (k == 1)
        {
            return min(nums1[start1], nums2[start2]);
        }
        int i = start1 + min(len1, k / 2) - 1;
        int j = start2 + min(len2, k / 2) - 1;

        if (nums1[i] > nums2[j])
        {
            return findKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
        }
        else
        {
            return findKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
        }
    }
};
// @lc code=end
