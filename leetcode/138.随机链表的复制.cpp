/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        Node* cur = head;
        while (cur)
        {
            Node* t = new Node(cur->val);
            t->next = cur->next;
            cur->next = t;
            cur = t->next;
        }
        cur = head;
        while (cur)
        {
            if (cur->random)
            {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        cur = head;
        Node* newHead = head->next;
        Node* copyCurr = newHead;
        while (cur)
        {
            cur->next = cur->next->next;
            if (copyCurr->next)
            {
                copyCurr->next = copyCurr->next->next;
            }
            cur = cur->next;
            copyCurr = copyCurr->next;
        }

        return newHead;
    }
};
// @lc code=end
