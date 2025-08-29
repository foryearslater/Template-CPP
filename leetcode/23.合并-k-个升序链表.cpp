/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        auto cmp = [&](ListNode* a, ListNode* b)
        {
            return a->val >b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)>q(cmp);
        for(auto x:lists)
        {
            if(x)
            q.push(x);
        }
        while(q.size())
        {
            auto t = q.top();
            q.pop();
            cur->next = t ;
            t = t->next;
            cur = cur->next;
            if(t)
            {
                q.push(t);
            }
        }
        return head->next;
    }
};
// @lc code=end
