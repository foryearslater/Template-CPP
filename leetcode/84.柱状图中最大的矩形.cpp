/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> s;
        int mx = 0;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++)
        {
            while (s.size() && heights[i] < heights[s.top()])
            {
                int h = heights[s.top()];
                s.pop();
                int l = s.empty() ? -1 : s.top();
                int w = i - l - 1;
                mx = max(mx, h * w);
            }
            s.push(i);
        }
        return mx;
    }
};
// @lc code=end
