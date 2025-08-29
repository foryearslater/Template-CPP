/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;
        int mx = 0;
        int cur = 0;
        for (int i = 0; i < n - 1; i++)
        {
            mx = max(mx, i + nums[i]);
            if (i == cur)
            {
                cnt++;
                cur = mx;
            }
        }
        return cnt;
    }
};
// @lc code=end
