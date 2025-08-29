/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m;
        for(int i=0;i<nums.size();i ++ )
        {
            int x=nums[i];
            
            if(m.count(target-x))
            {
                return {i,m[target-x]}; 
            }
            m[x] = i;
        }
        return {0,0};
    }
};
// @lc code=end

