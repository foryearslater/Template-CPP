/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int top = 0, bottom = matrix.size() - 1;
        int l = 0, r = matrix[0].size() - 1;
        while (top <= bottom && l <= r)
        {
            for (int j = l; j <= r; j++)
            {
                ans.push_back(matrix[top][j]);
            }
            top++;
            for (int j = top; j <= bottom; j++)
            {
                ans.push_back(matrix[j][r]);
            }
            r--;
            if (top <= bottom)
            {
                for (int j = r; j >= l; j--)
                {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            if (l <= r)
            {
                for (int j = bottom; j >= top; j--)
                {
                    ans.push_back(matrix[j][l]);
                }
                l++;
            }
        }
        return ans;
    }
};
// @lc code=end
