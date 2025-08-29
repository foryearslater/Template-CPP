/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0,head);
        ListNode* pre = &dummy;
        while(pre->next && pre->next->next)
        {
            ListNode* x = pre->next;
            ListNode* y = pre->next->next;
            pre->next = y;
            x->next = y->next;
            y->next =x;
            pre = x;
        }
        return dummy.next;
    }
};
// @lc code=end

