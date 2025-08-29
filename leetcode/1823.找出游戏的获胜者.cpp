/*
 * @lc app=leetcode.cn id=1823 lang=cpp
 *
 * [1823] 找出游戏的获胜者
 */

// @lc code=start
class Solution
{
public:
    int cal(int n, int k)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = (ans + k) % i;
        }
        return ans;
    }
    int findTheWinner(int n, int k)
    {
        return cal(n, k) + 1;
    }
};
// @lc code=end
