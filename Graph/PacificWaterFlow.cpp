//https://leetcode.com/problems/pacific-atlantic-water-flow/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> cord;

void bfs(queue<cord> &start, set<cord> &vis, vector<vector<int>> &heights) {
    int m = heights.size();
    int n = heights[0].size();
    while(not start.empty()) {
        cord curr = start.front();
        int curr_height = heights[curr.first][curr.second];
        start.pop();
        if (vis.find(curr) == vis.end()) {
            vis.insert(curr);
            //above
            if (curr.first != 0 and heights[curr.first-1][curr.second] >= curr_height)
                start.push({curr.first-1, curr.second});
            //below
            if(curr.first != m-1 and heights[curr.first+1][curr.second] >= curr_height)
                start.push({curr.first+1, curr.second});
            //left
            if (curr.second != 0 and heights[curr.first][curr.second-1] >= curr_height)
                start.push({curr.first, curr.second-1});
            //right
            if (curr.second != n-1 and heights[curr.first][curr.second+1] >= curr_height)
                start.push({curr.first, curr.second+1});
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    
    queue<cord> pacific_start;
    queue<cord> atlantic_start;
    set<cord> pacific_reach;
    set<cord> atlantic_reach;

    int m = heights.size();
    int n = heights[0].size();

    for (int j = 0; j < n; j++) {
        pacific_start.push({0,j});
        atlantic_start.push({m-1,j});
    }
    for(int i = 0; i < m; i++) {
        pacific_start.push({i,0});
        atlantic_start.push({i, n-1});
    }

    //run bfs
    bfs(atlantic_start, atlantic_reach, heights);
    bfs(pacific_start, pacific_reach, heights);

    vector<cord> vec(m*n);
    auto it = set_intersection(atlantic_reach.begin(), atlantic_reach.end(),
                        pacific_reach.begin(), pacific_reach.end(),
                        vec.begin());
    vec.resize(it-vec.begin());

    vector<vector<int>> res;
    for (auto v: vec) {
        res.push_back(vector<int>{v.first,v.second});
    }
    return res;
}

int main() {
    vector<vector<int>> heights {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> res = pacificAtlantic(heights);

    for (auto v: res) {
        cout<<"[";
        for (int n: v) {
            cout<<n<<" ";
        }
        cout<<"], ";
    }
    cout<<endl;
    return 0;
}

