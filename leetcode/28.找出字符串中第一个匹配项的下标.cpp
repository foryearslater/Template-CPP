/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.length();
        int m = needle.length();
        for (int i = 0; i <= n - m; ++i)
        {
            bool match = true;

            for (int j = 0; j < m; ++j)
            {

                if (haystack[i + j] != needle[j])
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end
