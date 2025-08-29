/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        int n = s.size(), m = p.size();
        if (n < m)
        {
            return res;
        }
        vector<int> cnt_s(26, 0);
        vector<int> cnt_p(26, 0);
        for (int i = 0; i < m; i++)
        {
            cnt_p[p[i] - 'a']++;
            cnt_s[s[i] - 'a']++;
        }
        if (cnt_p == cnt_s)
        {
            res.push_back(0);
        }
        for (int i = m; i < n; i++)
        {
            cnt_s[s[i] - 'a']++;
            cnt_s[s[i - m] - 'a']--;
            if (cnt_p == cnt_s)
            {
                res.push_back(i - m + 1);
            }
        }
        return res;
    }
};
// @lc code=end
