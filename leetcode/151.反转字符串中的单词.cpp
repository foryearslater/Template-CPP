/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> res;
        string t;
        for (auto x : s)
        {
            if (x == ' ')
            {
                if (t.size())
                {
                    res.push_back(t);
                }
                t.clear();
            }
            else
            {
                t += x;
            }
        }
        if (t.size())
        {
            res.push_back(t);
        }
        reverse(res.begin(), res.end());
        string str;
        for (int i = 0; i < res.size(); i++)
        {
            if (i)
                str += " ";
            str += res[i];
        }
        return str;
    }
};
// @lc code=end
