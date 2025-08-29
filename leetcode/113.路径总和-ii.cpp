/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(root, sum, path, paths);
        return paths;
    }
    void dfs(TreeNode *node, int sum, vector<int> &path, vector<vector<int>> &paths)
    {
        if (node == nullptr)
        {
            return;
        }
        path.push_back(node->val);
        if (!(node->left) && !(node->right) && sum == node->val)
        {
            paths.push_back(path);
        }
        dfs(node->left, sum - node->val, path, paths);
        dfs(node->right, sum - node->val, path, paths);
        path.pop_back();
    }
};
// @lc code=end
