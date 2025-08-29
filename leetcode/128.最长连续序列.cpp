/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s(nums.begin(), nums.end());
        int mx = 0;
        for (auto x : s)
        {
            if (s.find(x - 1) == s.end())
            {
                int cur = x;
                int len = 1;
                while (s.find(cur + 1) != s.end())
                {
                    cur++;
                    len++;
                }
                mx = max(mx, len);
            }
        }
        return mx;
    }
};
// @lc code=end
