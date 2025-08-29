/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x, int n)
    {
        long long b = n;
        if (b < 0)
        {
            x = 1 / x;
            b = -b;
        }
        double res = 1.0;
        while (b)
        {
            if (b & 1)
            {
                res = res * x;
            }
            x = x * x;
            b /= 2;
        }
        return res;
    }
};
// @lc code=end
