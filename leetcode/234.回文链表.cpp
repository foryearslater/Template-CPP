/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    ListNode* findMid(ListNode* head)
    {
        ListNode* slow = head, *fast = head;
        while(fast&&fast->next)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast)
            {
                fast = fast->next;
            }
        }
        return slow;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur)
        {
            auto t= cur->next;
            cur->next=pre;
            pre= cur;
            cur=t;
        }
        return pre;
    }
    bool cmp(ListNode* head1, ListNode* head2){
        while(head1 && head2){
            if(head1->val != head2->val) return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
    bool isPalindrome(ListNode *head)
    {
       ListNode* cur = head;
       auto mid = findMid(cur);
       auto h = reverse(mid);
       return cmp(head,h);
    }
};
// @lc code=end
