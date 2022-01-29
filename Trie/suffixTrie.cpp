#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    unordered_map <char, TrieNode*> hash_map; 
};

class suffixTrie {
    private: TrieNode *root;
    public:
    suffixTrie(string s) {
        root = new TrieNode();
        s += "$";
        TrieNode *curr;
        for (int i = 0; i < s.length(); i++) {
            curr = root;
            for (int j = i; j < s.length(); j++) {
                if (curr->hash_map.find(s[i]) == curr->hash_map.end()) {
                    curr->hash_map[s[i]] = new TrieNode;
                }
                curr = curr->hash_map[s[i]];
            }
        }
    }

    //Return node at end of path
    TrieNode * followPath(string s) {
        TrieNode *curr = root;
        for (char c : s) {
            if (curr->hash_map.find(c) == curr->hash_map.end())
                return nullptr;
            curr = curr->hash_map[c];
        }
        return curr;
    }

    bool hasSubstring(string sub) {
        return followPath(sub) != nullptr;
    }

    bool hasSuffix(string sfx) {
        TrieNode *node = followPath(sfx);
        return node != nullptr and node->hash_map.find('$')!= node->hash_map.end();
    }

};