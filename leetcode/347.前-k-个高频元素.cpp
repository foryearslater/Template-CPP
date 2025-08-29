/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> m;
        for (auto x : nums)
        {
            m[x]++;
        }
        priority_queue<pair<int, int>> q;
        for (auto x : m)
        {
            q.push({x.second, x.first});
        }
        vector<int> ans;
        while (q.size() > (int)m.size() - k)
        {
            ans.push_back(q.top().second);
            q.pop();
        }

        return ans;
    }
};
// @lc code=end
