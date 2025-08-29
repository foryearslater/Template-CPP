/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    ListNode *findmid(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *reverselist(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur)
        {
            auto t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        return pre;
    }
    void mergelist(ListNode *l1, ListNode *l2)
    {
        while (l2)
        {
            ListNode *next1 = l1->next;
            ListNode *next2 = l2->next;
            l1->next = l2;
            l2->next = next1;

            l1 = next1;
            l2 = next2;
        }
    }
    void reorderList(ListNode *head)
    {
        ListNode *mid = findmid(head);
        ListNode *reverse = reverselist(mid->next);
        mid->next = nullptr;
        mergelist(head, reverse);
    }
};
// @lc code=end
