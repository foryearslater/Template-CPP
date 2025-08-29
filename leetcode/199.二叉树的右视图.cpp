/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>ans;
        if(!root)
        {
            return ans;
        }
        q.push(root);
        while(q.size())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto t = q.front();
                q.pop();
                if(i==n-1)
                {
                    ans.push_back(t->val);
                }
                if(t->left)
                {
                    q.push(t->left);
                }
                if(t->right)
                {
                    q.push(t->right);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

