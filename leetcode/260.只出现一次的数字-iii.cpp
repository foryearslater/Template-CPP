/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        unsigned int  ans = 0;
        for (auto x : nums)
        {
            ans ^= x;
        }
        unsigned  int lowbit = (ans & -ans);
        int a = 0, b = 0;
        for (auto x : nums)
        {
            if (x & lowbit)
            {
                a ^= x;
            }
            else
            {
                b ^= x;
            }
        }
        return {a, b};
    }
};
// @lc code=end
