/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur = nums[0];
        int cnt = 1;
        int n = nums.size();
        for(int i = 1; i < n ;i ++)
        {
            if(cnt == 0) 
            {
                cur = nums[i];
                cnt = 1;
            }
            else if(nums[i] == cur) 
            {
                cnt ++;
            }
            else 
            {
                cnt --;
            }
           
        }
        return cur;
    }
};
// @lc code=end

