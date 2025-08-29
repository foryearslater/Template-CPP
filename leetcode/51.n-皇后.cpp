/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<int> queens(n, -1);
        dfs(n, 0, queens, res);
        return res;
    }
    void dfs(int n, int row, vector<int> &queens, vector<vector<string>> &res)
    {
        if (row == n)
        {
            vector<string> board(n, string(n, '.'));
            for (int i = 0; i < n; ++i)
            {
                board[i][queens[i]] = 'Q';
            }
            res.push_back(board);
            return;
        }
        for (int col = 0; col < n; ++col)
        {
            if (isValid(row, col, queens))
            {
                queens[row] = col;
                dfs(n, row + 1, queens, res);
                queens[row] = -1;
            }
        }
    }

    bool isValid(int row, int col, const vector<int> &queens)
    {
        for (int i = 0; i < row; ++i)
        {

            if (queens[i] == col || abs(row - i) == abs(col - queens[i]))
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
