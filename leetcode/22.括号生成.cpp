/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        dfs(res, "", 0, 0, n);
        return res;
    }
    void dfs(vector<string> &res, string current, int open, int close, int n)
    {
        if (current.length() == n * 2)
        {
            res.push_back(current);
            return;
        }
        if (open < n)
        {
            dfs(res, current + "(", open + 1, close, n);
        }
        if (close < open)
        {
            dfs(res, current + ")", open, close + 1, n);
        }
    }
};
// @lc code=end
