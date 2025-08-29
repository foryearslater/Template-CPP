/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>m;
        for(auto x:nums)
        {
            m[x]++;
            if(m[x]>=2)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

