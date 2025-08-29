/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0;
        int n = height.size();
        if (n == 0)
            return 0;
        vector<int> l(n + 1), r(n + 1);
        r[n - 1] = height[n - 1];
        l[0] = height[0];

        for (int i = n - 2; i >= 0; i--)
        {
            r[i] = max(height[i], r[i + 1]);
        }
        for (int i = 1; i < n; i++)
        {
            l[i] = max(height[i], l[i - 1]);
        }
        for (int i = 0; i < n; i++)
        {
            ans += min(l[i], r[i]) - height[i];
        }

        return ans;
    }
};
// @lc code=end
