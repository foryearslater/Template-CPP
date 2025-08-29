/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> ans;
        if (root == nullptr)
        {
            return ans;
        }
        q.push(root);
        int cnt = 0;
        while (q.size())
        {
            auto n = q.size();
            vector<int> v;
            vector<TreeNode *> node;
            while (n--)
            {
                auto t = q.front();
                q.pop();
                v.push_back(t->val);
                if (t->left)
                {
                    q.push(t->left);
                }
                if (t->right)
                {
                    q.push(t->right);
                }
            }

            if ((cnt & 1))
            {
                reverse(v.begin(), v.end());
            }
            ans.push_back(v);
            cnt++;
        }
        return ans;
    }
};
// @lc code=end
