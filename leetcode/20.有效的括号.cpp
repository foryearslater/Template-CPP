/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (auto x : s)
        {
            if (x == '}' || x == ')' || x == ']')
            {
                if(stk.empty())
                {
                    return false;
                }
                auto top = stk.top();
                stk.pop();
                if ((x == ')' && top != '(') ||
                    (x == ']' && top != '[') ||
                    (x == '}' && top != '{'))
                {
                    return false;
                }
            }
            else
            {
                stk.push(x);
            }
        }
        if (stk.size())
        {
            return false;
        }
        return true;
    }
};
// @lc code=end
