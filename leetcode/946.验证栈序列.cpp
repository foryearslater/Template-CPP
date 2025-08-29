/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

// @lc code=start
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> s;
        int i = 0;
        for (auto num : pushed)
        {
            s.push(num);
            while (s.size() && s.top() == popped[i])
            {
                s.pop();
                i++;
            }
        }
        return i == popped.size();
    }
};
// @lc code=end
