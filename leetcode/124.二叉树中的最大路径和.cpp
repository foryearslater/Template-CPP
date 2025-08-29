/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }
    int dfs(TreeNode *node, int &sum)
    {
        if (!node)
            return 0;
        int l = max(dfs(node->left, sum), 0);
        int r = max(dfs(node->right, sum), 0);
        int cur = l + r + node->val;
        sum = max(sum, cur);
        return node->val + max(l, r);
    };
};
// @lc code=end
