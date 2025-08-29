/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= 0)
            {
                nums[i] = n + 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            int x = abs(nums[i]);
            if (x <= n)
            {
                nums[x - 1] = -abs(nums[x - 1]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            std::cout << nums[i] << endl;
            if (nums[i]>0)
            {

                return i + 1;
            }
        }
        return n + 1;
    }
};
// @lc code=end
