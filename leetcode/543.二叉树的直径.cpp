/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int ans = 0;
    int height(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int l = height(root->left);
        int r = height(root->right);
        ans = max(ans, l + r + 1);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        height(root);
        return ans - 1;
    }
};
// @lc code=end
