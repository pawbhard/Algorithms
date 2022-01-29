//To get SCC of a directed graph

#include<bits/stdc++.h>

using namespace std;
typedef vector<vector<int>> adj_list;

void reverseGraph(adj_list &adj, int &n, adj_list &rev_adj) {
    rev_adj.resize(n, vector<int> {});
    for(int i = 0; i < n; i++) {
        for (int neigh: adj[i]) {
            rev_adj[neigh].push_back(i);
        }
    }
}

//Assign topological numbering to graph
void _dfs(adj_list &adj, int curr, int &val, vector<int> &topo, vector<bool> &vis) {
    vis[curr] = true;
    for(auto n: adj[curr]) {
        if (not vis[n])
            _dfs(adj, n, val, topo, vis);
    }
    topo[val++] = curr;
}

void _dfs_simple(adj_list &adj, int curr, vector<bool> &vis, vector<int> &comp) {
    vis[curr] = true;
    comp.push_back(curr);
    for(auto n: adj[curr]) {
        if (not vis[n])
            _dfs_simple(adj, n, vis, comp);
    }
}

int kosaraju_alogo(adj_list &adj, int &n) {
    
    //Step 1 reverse graph
    adj_list rev_adj;
    reverseGraph(adj, n, rev_adj);

    //Step2 . find topo number on reverse graph
    vector<int> topo(n, INT_MAX);
    vector<bool> vis(n, false);
    int val = 0;
    for(int i = 0; i < n; i++) {
        if (not vis[i])
            _dfs(rev_adj, i, val, topo, vis);
    }

    //cout<<"Topo ";
    //copy(topo.begin(), topo.end(), ostream_iterator<int>(cout, " ")); cout<<"\n";

    //Step 3: Use this topo number from max to minimum to run DFs and cout SCC
    vis.clear();
    vis.resize(n, false);
    int scc = 0;
    vector<int> comp{};
    for(auto it = topo.rbegin(); it != topo.rend(); it++) {
        if (not vis[*it]) {
            cout<<"Starting with "<<*it<<"\n";
            scc++;
            comp.clear();
            _dfs_simple(adj,*it, vis, comp);
            cout<<"Component-"<<scc<<": ";
            copy(comp.begin(), comp.end(), ostream_iterator<int>(cout," "));cout<<"\n";
        }
    }
    return scc;
}


int main() {
    //Input adjency list
    int n = 11;
    adj_list adj(11, vector<int>{});
    adj[0] = vector<int> {2};
    adj[1] = vector<int> {3, 9};
    adj[2] = vector<int> {4, 10};
    adj[3] = vector<int> {6};
    adj[4] = vector<int> {6,8,0};
    adj[5] = vector<int> {9};
    adj[6] = vector<int> {8};
    adj[7] = vector<int> {5};
    adj[8] = vector<int> {1, 3, 7};
    adj[9] = vector<int> {7};
    adj[10] = vector<int> {5, 7}; 

    int scc = kosaraju_alogo(adj, n);
    cout<<"Strongly connected Component "<<scc<<"\n";
}