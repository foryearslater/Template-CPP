/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *pre = dummy;
        ListNode *cur = head;
        int len = 0;
        while (cur != nullptr)
        {
            cur = cur->next;
            len++;
        }
        cur = head;
        for (int i = 0; i < len / k; i++)
        {
            ListNode *first = cur;
            ListNode *last = pre;
            for (int j = 0; j < k; j++)
            {
                ListNode *t = cur->next;
                cur->next = last;
                last = cur;
                cur = t;
            }
            pre->next = last;
            first->next = cur;
            pre = first;
        }
        return dummy->next;
    }
};
// @lc code=end
