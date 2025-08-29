/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> path;
        dfs(s, 0, path, res);
        return res;
    }
    void dfs(const string &s, int start, vector<string> &path, vector<vector<string>> &res)
    {
        if (start == s.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); ++i)
        {
            if (check(s, start, i))
            {
                path.push_back(s.substr(start, i - start + 1));
                dfs(s, i + 1, path, res);
                path.pop_back();
            }
        }
    }

    bool check(const string &s, int left, int right)
    {
        while (left < right)
        {
            if (s[left++] != s[right--])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
