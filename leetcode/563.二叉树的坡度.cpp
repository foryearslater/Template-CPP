/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
class Solution {
public:
    int findTilt(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
     int dfs(TreeNode* node, int& ans) {
        if (!node) return 0;
        
        int leftSum = dfs(node->left, ans);
        int rightSum = dfs(node->right, ans);
        
        ans += abs(leftSum - rightSum);
        
        return leftSum + rightSum + node->val;
    }
};
// @lc code=end

