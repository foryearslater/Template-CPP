/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class TrieNode
{
public:
    bool is_word;
    TrieNode *children[26];
    TrieNode()
    {
        is_word = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};
class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        int len = word.size();
        int k = 0;
        TrieNode *cur = root;
        for (int i = 0; i < len; i++)
        {
            k = word[i] - 'a';
            if (cur->children[k] == nullptr)
            {
                cur->children[k] = new TrieNode();
            }
            cur = cur->children[k];
        }
        cur->is_word = true;
    }

    bool search(string word)
    {
        int len = word.size();
        int k = 0;
        TrieNode *cur = root;
        for (int i = 0; i < len; i++)
        {
            k = word[i] - 'a';
            cur = cur->children[k];
            if (cur == nullptr)
            {
                return false;
            }
        }
        return cur->is_word;
    }

    bool startsWith(string prefix)
    {
        int len = prefix.size();
        int k = 0;
        TrieNode *cur = root;
        for (int i = 0; i < len; i++)
        {
            k = prefix[i] - 'a';
            cur = cur->children[k];
            if (cur == nullptr)
            {
                return false;
            }
        }
        return true;
    }

private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
