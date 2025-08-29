/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution
{
public:
    string decodeString(string s)
    {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ']')
            {
                stk.push(s[i]);
            }
            else
            {
                string cur;
                while (stk.top() != '[')
                {
                    cur = stk.top() + cur;
                    stk.pop();
                }
                stk.pop();
                string num;
                while (stk.size() && isdigit(stk.top()))
                {
                    num = stk.top() + num;
                    stk.pop();
                }
                int cnt = stoi(num);
                while (cnt--)
                {
                    for (auto x : cur)
                    {
                        stk.push(x);
                    }
                }
            }
        }
        s = "";
        while (stk.size())
        {
            s = stk.top() + s;
            stk.pop();
        }
        return s;
    }
};
// @lc code=end
