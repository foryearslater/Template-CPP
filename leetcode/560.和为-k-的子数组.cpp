/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        map<int,int>m;
        m[0]=1;
        int pre=0;
        int cnt=0;
        for(auto x:nums)
        {
            pre+=x;
            int need = pre-k;
            if(m.find(need) !=m.end())
            {
                cnt +=m[need];
            }
            m[pre]++;
        }
        return cnt;
    }
};
// @lc code=end
