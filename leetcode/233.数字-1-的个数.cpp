/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start
class Solution
{
public:
    int countDigitOne(int n)
    {
        long ones = 0, m = 1, r = 1;
        while (n)
        {
            ones += (n + 8) / 10 * m + (n % 10 == 1) * r;
            r += n % 10 * m;
            m *= 10;
            n /= 10;
        }
        return ones;
    }
};
// @lc code=end
