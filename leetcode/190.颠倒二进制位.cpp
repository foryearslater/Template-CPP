/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution
{
public:
    int reverseBits(int n)
    {
        unsigned int x = n;
        unsigned int res = 0;
        for (int i = 0; i < 32; i++)
        {
            res = (res << 1) | (x & 1);
            x >>= 1;
        }
        return res;
    }
};
// @lc code=end
