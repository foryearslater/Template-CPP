strut
/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head = new ListNode(0);
        int carry = 0;
        ListNode* cur = head;
        while(l1||l2||carry)
        {
            int x = l1 ? l1->val:0;
            int y = l2 ? l2->val:0;
            ListNode* dummy = new ListNode();
            dummy->val = (x + y + carry )%10;
            carry = (x + y + carry)/10;
            cur->next = dummy;
            cur = cur->next;
            if(l1) 
            {
                l1 = l1->next;
            }
            if(l2)
            {
                l2 = l2->next;
            }
        }
        return head->next;
    }
};
// @lc code=end

