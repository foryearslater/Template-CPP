/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> g(numCourses);
        vector<int> in(numCourses, 0);
        for (auto &p : prerequisites)
        {
            g[p[1]].push_back(p[0]);
            in[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if(in[i] == 0)
            {
                q.push(i);
            }
        }
        int cnt = 0;
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            cnt++;
            for (auto v : g[u])
            {
                if (--in[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        return cnt == numCourses;
    }
};
// @lc code=end
