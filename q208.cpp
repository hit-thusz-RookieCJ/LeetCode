#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
    vector<Trie*> children;
    bool is_End;

    Trie* search_prefix(string s)
    {
        Trie* node = this;
        for(char c : s)
        {
            c -= 'a';
            if(node->children[c] == nullptr)
            {
                return nullptr;
            }
            node = node->children[c];
        }
        return node;
    }


public:
    /** Initialize your data structure here. */
    Trie(): children(26), is_End(false) {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for(char c : word)
        {
            c -= 'a';
            if(node->children[c] == nullptr)
            {
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        node->is_End = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this->search_prefix(word);
        return node && node->is_End;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return this->search_prefix(prefix);
    }
};
