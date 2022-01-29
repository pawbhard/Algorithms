// Prim minimum spanning tree Graph
#include<bits/stdc++.h>

using namespace std;
typedef vector<vector<int>> adj_matrix;
struct edge {
    int from;
    int to;
    int weight;
    edge(int _from, int _to, int _wt) {
        from = _from;
        to = _to;
        weight = _wt;
    }
};

struct compare {
    bool operator()(const edge &e1, const edge &e2) {
        return e1.weight > e2.weight;
    }
};

int prim_msp(adj_matrix &adj) {
    int sz = adj.size();
    vector<bool> vis (sz, false);
    priority_queue<edge, vector<edge>, compare> pq;
    int count = 1;
    int start_vertex = 0;
    vis[start_vertex] = true;
    for (int j = 0; j < sz; j++) {
        if (adj[start_vertex][j] != 0)
            pq.push(edge(start_vertex, j, adj[start_vertex][j]));
    }
    int cost = 0;
    while (count != sz) {
        if (pq.empty()) {
            cout<<"NOt able to create MSP all node not connected";
            return -1;
        }
        //get smallest edge
        auto e = pq.top();
        pq.pop();
        if (vis[e.to]) continue;
        cout<<"Using edge "<<e.from<<"-"<<e.to<<" wt:"<<e.weight<<"\n";
        cost+= e.weight;
        vis[e.to] = true;
        count++;
        for(int j = 0; j < sz; j++) {
            if (not vis[j] and adj[e.to][j] != 0)
                pq.push(edge(e.to, j, adj[e.to][j]));
        }
    }
    return cost;
}

int main() {
    adj_matrix adj {
        {0, 4, 0, 0, 0, 2},
        {4, 0, 6, 0, 0, 3},
        {0, 6, 0, 3, 0, 1},
        {0, 0, 3, 0, 2, 0},
        {0, 0, 0, 2, 0, 4},
        {2, 3, 1, 0, 4, 0},
    };
    int cost = prim_msp(adj);
    cout<<"Msp cost : "<<cost<<"\n";
    return 0;
}