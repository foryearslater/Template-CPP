/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        for(auto x:nums)
        {
            auto t = lower_bound(ans.begin(),ans.end(),x);
            if(t==ans.end())
            {
                ans.push_back(x);
            }
            else
            {
                *t = x;
            }
        }
        return ans.size();
    }
};
// @lc code=end

