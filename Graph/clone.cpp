//
#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

void dfs(Node * curr, unordered_set<Node*> &vis, unordered_map<Node*,Node*> &copies) {
    //find or create a copy
    if (vis.find(curr) != vis.end()) return;
    cout<<"On node : "<<curr->val<<endl;
    vis.insert(curr);
    auto it = copies.find(curr);
    Node *n;
    if(it == copies.end()) {
        n = new Node(curr->val);
        copies[curr] = n;
    } else {
        n = it->second;
    }

    for(auto neigh: curr->neighbors) {
        dfs(neigh, vis, copies);
        n->neighbors.push_back(copies[neigh]);
    }
    return;
}

Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> hash_map;
    unordered_set<Node*> vis{};
    dfs(node, vis, hash_map);
    return hash_map[node];
}