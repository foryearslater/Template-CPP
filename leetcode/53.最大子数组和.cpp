/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int sum = 0;
        for(auto x:nums)
        {
            ans=max(ans,sum+x);
            sum=sum+x;
            if(sum<0) sum=0;
        }
        return ans;
    }
};
// @lc code=end

