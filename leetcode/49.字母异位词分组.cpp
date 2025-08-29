/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        map<string,vector<string>>m;
        for(auto x:strs)
        {
            auto t = x;
            ranges::sort(t);
            m[t].push_back(x);
        }
        for(auto x:m)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};
// @lc code=end

