/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        auto cal = [&](int l, int r) -> int
        {
            while (l >= 0 && r < n && s[l] == s[r])
            {
                l--;
                r++;
            }
            return r - l - 1;
        };
        int start = 0;
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            int len1 = cal(i, i);
            int len2 = cal(i, i + 1);
            std::cout << len1 << " "<< len2 <<std::endl;
            int len = max(len1, len2);
            if (len > mx)
            {
                mx = len;
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, mx);
    }
};
// @lc code=end
