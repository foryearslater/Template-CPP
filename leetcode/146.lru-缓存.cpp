/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
struct Node
{
    int key;
    int value;
    Node *pre;
    Node *next;
    Node(int key = 0, int value = 0) : key(key), value(value) {}
};
class LRUCache
{
public:
    Node *dummy;
    int capacity;
    map<int, Node *> m;
    LRUCache(int capacity) : capacity(capacity), dummy(new Node())
    {
        dummy->next = dummy;
        dummy->pre = dummy;
    }
    void remove(Node *node)
    {
        node->next->pre = node->pre;
        node->pre->next = node->next;
    }
    void push_front(Node *node)
    {
        node->pre = dummy;
        node->next = dummy->next;
        node->next->pre = node;
        node->pre->next = node;
    }
    Node *get_node(int key)
    {
        auto it = m.find(key);
        if (it == m.end())
        {
            return nullptr;
        }
        Node *node = it->second;
        remove(node);
        push_front(node);
        return node;
    }
    int get(int key)
    {
        auto node = get_node(key);
        return node ? node->value : -1;
    }

    void put(int key, int value)
    {
        auto it = get_node(key);
        if (it)
        {
            m[key]->value = value;
            return;
        }
        m[key] = it = new Node(key, value);
        push_front(it);
        if (m.size() > capacity)
        {
            auto t = dummy->pre;
            remove(t);
            m.erase(t->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
