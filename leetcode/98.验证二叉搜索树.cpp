/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode *root)
    {
        return isvalid(root, nullptr, nullptr);
    }
    bool isvalid(TreeNode *root, int *l, int *r)
    {
        if (!root)
        {
            return true;
        }
        if (r && root->val >= *r)
        {
            return false;
        }
        if (l && root->val <= *l)
        {
            return false;
        }
        return isvalid(root->left, l, &(root->val)) && isvalid(root->right, &(root->val), r);
    }
};
// @lc code=end
