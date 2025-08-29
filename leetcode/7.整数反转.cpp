/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        int res = 0;
        while (x)
        {
            int d = x % 10;
            x /= 10;
            if (res > INT_MAX / 10 ||
                (res == INT_MAX / 10 && d > 7))
            {
                return 0;
            }

            if (res < INT_MIN / 10 ||
                (res == INT_MIN / 10 && d < -8))
            {
                return 0;
            }
            res = res * 10 + d;
        }
        return res;
    }
};
// @lc code=end
