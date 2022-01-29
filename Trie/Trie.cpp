#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    TrieNode* alphabet[26];
    bool isEnd;

    TrieNode() : isEnd(false) {
        for (int i =0 ; i < 26; i++) {
            alphabet[i] = nullptr;
        }
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode;
    }
    
    void insert(string word) {
        //isLower(word);
        TrieNode *tmp = root;
        for(char c: word) {
            if(tmp->alphabet[c-'a'] == nullptr) {
                tmp->alphabet[c-'a'] = new TrieNode;
            }
            tmp = tmp->alphabet[c-'a'];
        }
        tmp->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *tmp = root;
        for (char c: word) {
            if(tmp->alphabet[c-'a'] == nullptr) return false;
            tmp = tmp->alphabet[c-'a'];
        }
        return tmp and tmp->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *tmp = root;
        for (char c: prefix) {
            if (tmp->alphabet[c-'a'] ==nullptr) return false;
            tmp = tmp->alphabet[c-'a'];
        }
        return tmp;
    }

    bool _worker(TrieNode *curr, string s) {
        if(curr == nullptr) return false;
        if (s.length() == 0) return curr->isEnd;

        string sub = s.substr(1);
        if (s[0] == '.') {
            
            for(int i = 0; i < 26; i++) {
                if(_worker(curr->alphabet[i], sub))
                    return true;
            }
            return false;
        } else {
            return _worker(curr->alphabet[s[0]-'a'], sub);
        }

    }
    //search .ell or h...
    bool searchWildCard(string word) {
        TrieNode *tmp = root;
        return _worker(tmp, word);
    }
};


int main() {
    Trie t;
    t.insert("hello");
    t.insert("help");
    cout<<boolalpha;
    //cout<<t.search("helping")<<endl;
    cout<<t.searchWildCard("he..p")<<endl;
    //cout<<t.startsWith("he")<<endl;
    return 0;
}