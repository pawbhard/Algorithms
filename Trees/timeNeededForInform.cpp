#include <bits/stdc++.h>
using namespace std;
int dfs(int mgr, unordered_map<int,vector<int>> &tree, vector<int> &informTime) {
    auto it = tree.find(mgr);
    if(it == tree.end()) return 0;
    int mx_time = 0;
    for(int m: it->second) {
        int val = dfs(m, tree, informTime);
        if (val > mx_time)
            mx_time = val;
    }
    if (mgr != -1) mx_time+= informTime[mgr];
    return mx_time;
}

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    unordered_map<int, vector<int>> tree;
    for (int i = 0; i < manager.size(); i++) {
        auto it = tree.find(manager[i]);
        if (it == tree.end()) {
            tree[manager[i]] = vector<int> {i};
        } else {
            it->second.push_back(i);
        }
    }
    return dfs(-1, tree, informTime);
}

int main() {
    int n= 1;//6;
    int headID = 0;
    vector<int> manager {-1}; //{2,2,-1,2,2,3};
    vector<int> informTime {0};//{0,0,1,3,0,0};
    cout<<numOfMinutes(n,headID, manager, informTime)<<endl;
    return 0;
}