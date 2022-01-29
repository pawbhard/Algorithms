//https://leetcode.com/problems/minimum-height-trees/
#include<bits/stdc++.h>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    
    //Create adj list
    unordered_map<int, vector<int>> adj;
    for (auto v: edges) {
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    
    queue<int> q;
    unordered_set<int> st;
    for(int i = 0; i < n; i++) {
        st.insert(i);
        if(adj[i].size()==1) q.push(i);
    }

    
}