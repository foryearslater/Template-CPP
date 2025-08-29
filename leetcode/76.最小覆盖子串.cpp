/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size(), m = t.size();
        string ans;
        if (n < m)
        {
            return ans;
        }
        map<char, int> cnt_s;
        map<char, int> cnt_t;
        for (auto x : t)
        {
            cnt_t[x]++;
        }
        int mi = INT_MAX;
        int cnt = 0;
        for (int slow = 0, fast = 0; fast < s.size(); fast++)
        {
            char c = s[fast];
            if (cnt_t.find(c) != cnt_t.end())
            {
                cnt_s[c]++;
                if (cnt_s[c] <= cnt_t[c])
                {
                    cnt++;
                }
            }
            if (cnt >= t.size())
            {
                while (cnt_t.find(s[slow]) == cnt_t.end() || cnt_s[s[slow]] > cnt_t[s[slow]])
                {
                    cnt_s[s[slow]]--;
                    slow++;
                }
                if (fast - slow + 1 < mi)
                {
                    mi = fast - slow + 1;
                    ans = s.substr(slow, mi);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
