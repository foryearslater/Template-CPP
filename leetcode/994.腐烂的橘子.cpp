/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int cnt = 0;
        int time = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    cnt++;
                }
            }
        }

        if (cnt == 0)
        {
            return 0;
        }
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty())
        {
            int size = q.size();
            bool flag = false;
            for (int i = 0; i < size; ++i)
            {
                auto cur = q.front();
                q.pop();
                for (auto dir : dirs)
                {
                    int x = cur.first + dir.first;
                    int y = cur.second + dir.second;
                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1)
                    {
                        grid[x][y] = 2;
                        q.push({x, y});
                        cnt--;
                        flag = true;
                    }
                }
            }
            if (flag)
            {
                time++;
            }
        }

        return cnt == 0 ? time : -1;
    }
};
// @lc code=end
