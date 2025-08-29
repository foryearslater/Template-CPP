/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution
{
public:
    int addDigits(int num)
    {
        if (num % 9 == 0 && num != 0)
        {
            return 9;
        }
        else
        {
            return num % 9;
        }
    }
};
// @lc code=end
