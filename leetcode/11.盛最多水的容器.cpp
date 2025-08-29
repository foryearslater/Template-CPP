/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int ans = 0;
        int l = 0, r = n - 1;
        while (l < r)
        {
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
    }
};
// @lc code=end
