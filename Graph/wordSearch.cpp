#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>> &board, vector<vector<bool>> &vis, int i, int j, string word) {
    if (board[i][j] != word[0]) return false;
    if (word.length() == 1) return true;

    string sub = word.substr(1);
    int m = board.size();
    int n = board[0].size();
    //up
    
    if (i != 0 and not vis[i-1][j]){
        vis[i-1][j] = true;
        if(dfs(board, vis, i-1, j, sub)) return true;
        vis[i-1][j] = false;
    }

    //down
    if (i != m-1 and not vis[i+1][j]) {
        vis[i+1][j] = true;
        if(dfs(board, vis, i+1, j, sub)) return true;
        vis[i+1][j] = false;
    }
    //left
    if (j != 0 and not vis[i][j-1]) {
        vis[i][j-1] = true;
        if (dfs(board, vis, i, j-1, sub)) return true;
        vis[i][j-1] = false;
    } 
    //right
    if(j != n-1 and not vis[i][j+1]) {
        vis[i][j+1] = true;
        if (dfs(board, vis, i, j+1, sub)) return true;
        vis[i][j+1] = false;
    }
    return false;
}
bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            vector<vector<bool>> vis(m, vector<bool>(n,0));
            if (dfs(board, vis, i, j, word)) return true;
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board {{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
    string word ="ABCESEEEFS";
    cout<<exist(board,word)<<endl;
    return 0;
}