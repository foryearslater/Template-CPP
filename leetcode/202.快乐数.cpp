/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution
{
public:
    bool isHappy(int n)
    {
        auto check = [&](int x)
        {
            int sum = 0;
            string s = to_string(x);
            for (auto x : s)
            {
                sum += pow(x - '0', 2);
            }
            return sum;
        };
        int slow = n;
        int fast = n;
        while (1)
        {
            slow = check(slow);
            fast = check(check(fast));
            if (fast == 1)
            {
                return true;
            }
            if (fast == slow)
            {
                return false;
            }
        }
    }
};
// @lc code=end
