/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int close = nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i] == nums[i-1]) continue;
            int l = i+1,r=n-1;
            while(l<r)
            {
                int cur = nums[i]+nums[l]+nums[r];
                if(cur==target)
                {
                    return target;
                }
                if(abs(cur-target)<abs(close-target))
                {
                    close = cur;
                }
                if(cur<target)
                {
                    l++;
                    while(l<r&&nums[l] == nums[l-1])l++;
                }
                else 
                {
                    r--;
                    while(l<r&&nums[r]==nums[r+1]) r--;
                }
                
            }
        }
        return close;
    }
};
// @lc code=end

