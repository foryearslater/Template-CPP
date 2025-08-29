/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int i = num1.size() - 1, j = num2.size() - 1;
        int carry = 0;
        string res = "";
        while (i>=0 || j>=0 || carry)
        {
            int sum = carry;
            if (i >= 0)
            {
                sum += num1[i] - '0';
                i--;
            }
            if (j >= 0)
            {
                sum += num2[j] - '0';
                j--;
            }
            carry = sum / 10;
            res += ('0' + sum % 10);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
