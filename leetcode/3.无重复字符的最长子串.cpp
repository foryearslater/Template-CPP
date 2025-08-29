/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int res = 0;
        int n = s.size();
        map<char, int> m;
        int l = 0;
        for (int i = 0; i < n; i++)
        {
            m[s[i]]++;
            while (m[s[i]] > 1)
            {
                m[s[l++]]--;
            }
            res = max(res, i - l+ 1);
        }
        return res;
    }
};
// @lc code=end
