/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */

// @lc code=start
class Solution
{
public:
    bool isNumber(string s)
    {
        size_t start = s.find_first_not_of(' ');
        if (start == string::npos)
            return false;
        size_t end = s.find_last_not_of(' ');
        s = s.substr(start, end - start + 1);

        bool numSeen = false;
        bool dotSeen = false;
        bool eSeen = false;
        bool numAfterE = true;

        for (int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            if (isdigit(c))
            {
                numSeen = true;
                numAfterE = true;
            }
            else if (c == '.')
            {
                if (dotSeen || eSeen)
                    return false;
                dotSeen = true;
            }
            else if (c == 'e' || c == 'E')
            {
                if (eSeen || !numSeen)
                    return false;
                eSeen = true;
                numAfterE = false;
            }
            else if (c == '+' || c == '-')
            {
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else
            {
                return false;
            }
        }

        return numSeen && numAfterE;
    }
};
// @lc code=end
