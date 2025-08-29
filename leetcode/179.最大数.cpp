/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        auto cmp = [&](string a, string b)
        {
            return a + b > b + a;
        };
        vector<string> v;
        for (auto x : nums)
        {
            v.push_back(to_string(x));
        }
        sort(v.begin(), v.end(), cmp);
        string res;
        for (auto x : v)
        {
            res += x;
        }
        return res[0] == '0' ? "0" : res;
    }
};
// @lc code=end
