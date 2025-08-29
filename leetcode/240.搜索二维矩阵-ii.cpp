/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size(), l = 0, r = m - 1;
        while (l < n && r >= 0)
        {
            if (matrix[l][r] == target)
            {
                return true;
            }
            matrix[l][r] > target ? r-- : l++;
        }
        return false;
    }
};
// @lc code=end
