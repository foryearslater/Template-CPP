/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int mx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > mx)
            {
                return false;
            }
            mx = max(mx, nums[i] + i);
            if (mx >= nums.size() - 1)
            {
                return true;
            }
        }
        return true;
    }
};
// @lc code=end
