#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    vector<TrieNode*> child;
    TrieNode() { 
        child = vector<TrieNode*>(26, nullptr);
        word = "";
    }
    string word;
};

class Trie {
    TrieNode *root;
public:
    Trie(vector<string> &words) {
        root = new TrieNode();
        for(auto s : words) {
            addWord(s);
        }
    }

    void addWord(string s) {
        TrieNode *curr = root;
        for (char c : s) {
            if (curr->child[c-'a'] == nullptr) {
                curr->child[c-'a'] = new TrieNode;
            }
            curr = curr->child[c-'a'];
        }
        curr->word = s;
    }

    void _findWords(vector<vector<char>>& board,int i, int j, TrieNode *curr, vector<string> &res) {
        char c = board[i][j];
        if (c == ' ' or not  curr->child[c-'a']) return;

        curr = curr->child[c-'a'];
        if (curr->word.size() > 0) {
            res.push_back(curr->word);
            curr->word = "";
        }
        
        board[i][j] = ' ';
        if (i > 0) _findWords(board, i-1, j, curr, res);
        if (i < board.size()-1) _findWords(board, i+1, j, curr, res);
        if (j > 0) _findWords(board, i, j-1, curr, res);
        if (j < board[0].size()-1) _findWords(board, i, j+1, curr, res);
        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board) {
        vector<string> res;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                _findWords(board, i, j, root, res);
            }
        }

    return res;
    }
};

int main() {
    vector<vector<char>> board {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words {"oath","pea","eat","rain"};
    Trie t(words);
    vector<string> res = t.findWords(board);
    return 0;
}