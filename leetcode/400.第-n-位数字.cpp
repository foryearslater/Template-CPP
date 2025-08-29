/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 */

// @lc code=start
class Solution
{
public:
    int findNthDigit(int n)
    {
        long base = 1;
        int digit = 1;
        long cnt = 9;
        while (n > cnt)
        {
            n -= cnt;
            base *= 10;
            digit++;
            cnt = 9 * base * digit;
        }
        long num = base + (n - 1) / digit;
        string s = to_string(num);
        return s[(n - 1) % digit] - '0';
    }
};
// @lc code=end
