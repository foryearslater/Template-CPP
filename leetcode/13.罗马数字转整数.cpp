/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> m = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int cur = m[s[i]];
            if (i < s.size() - 1 && cur < m[s[i + 1]])
            {
                res -= cur;
            }
            else
            {
                res += cur;
            }
        }
        return res;
    }
};
// @lc code=end
