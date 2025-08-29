/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int dx[] = {-1, 0, 0, 1}, dy[] = {0, 1, -1, 0};
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<vector<int>> st(n, vector<int>(m, 0));
        function<void(int, int)> dfs = [&](int i, int j)
        {
            if (i < 0 || i >= n || j < 0 || j >= m)
                return;
            if (grid[i][j] != '1')
                return;

            grid[i][j] = '0';

            for (int dir = 0; dir < 4; dir++)
            {
                int x = i + dx[dir], y = j + dy[dir];
                dfs(x, y);
            }
        };
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
