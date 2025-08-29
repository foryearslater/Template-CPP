/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for (int i = n - 2; i >= 0; i--)
        {
            int j = i + 1;
            while (true)
            {
                if (temperatures[i] < temperatures[j])
                {
                    ans[i] = j - i;
                    break;
                }
                else if (ans[j] == 0)
                {
                    ans[i] = 0;
                    break;
                }
                j += ans[j]; 
            }
        }
        return ans;
    }
};
// @lc code=end
