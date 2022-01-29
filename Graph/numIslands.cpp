#include<bits/stdc++.h>
using namespace std;
void bfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int, int>> q;
    q.push({i,j});
    while(not q.empty()) {
        auto p = q.front();
        i = p.first;
        j = p.second;
        q.pop();
        if (vis[p.first][p.second]) continue;
        vis[p.first][p.second] = 1;
        //up
        if(i != 0 and grid[i-1][j]=='1' and not vis[i-1][j]) q.push({i-1, j});
        //down
        if(i != m-1 and grid[i+1][j]=='1' and not vis[i+1][j]) q.push({i+1, j});
        //left
        if(j != 0 and grid[i][j-1] == '1' and not vis[i][j-1]) q.push({i, j-1});
        //right
        if(j != n-1 and grid[i][j+1] == '1' and not vis[i][j+1]) q.push({i, j+1});
    }
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> vis(m, vector<bool>(n, 0));
    int num = 0;

    for (int i = 0; i < m ;i++) {
        for (int j = 0; j < n; j++) {
            if(vis[i][j]) continue;
            if (grid[i][j] == '1') {
                num++;
                bfs(i, j, vis, grid);
            }
        }
    }
    return num;    
}

int main() {
    vector<vector<char>> grid {{'1','1','0','0','0'},
                                {'1','1','0','0','0'},
                                {'0','0','1','0','0'},
                                {'0','0','0','1','1'}};
    
    cout<<numIslands(grid)<<endl;
    return 0;
                
}