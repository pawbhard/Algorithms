#include <bits/stdc++.h>

using namespace std;

struct ver{
    int from;
    int to;
    int wt;
    ver(int _from, int _to, int _wt) { from = _from; to = _to; wt = _wt;}
};

struct compare {
    bool operator()(const ver &v1, const ver &v2) {
        return v1.wt > v2.wt;
    }
};

void dijkstra(vector<vector<int>> &graph, int start_vertex) {
    int sz = graph.size();
    vector<int> dist(sz, INT_MAX);
    vector<bool> added(sz, false);
    dist[start_vertex] = 0;
    added[start_vertex] = true;

    priority_queue<ver, vector<ver>, compare> pq;
    for(int j = 0; j < sz; j++) {
        if (graph[start_vertex][j] != 0) {
            pq.push(ver(start_vertex, j, graph[start_vertex][j]));
        }
    }

    int count = 1;
    while (count != sz) {
        ver v = pq.top();
        pq.pop();

        if(added[v.to]) continue;
        dist[v.to] = dist[v.from] + v.wt;
        added[v.to] = true;
        count++;
        for(int j = 0; j < sz; j++) {
            if (graph[v.to][j] != 0 and not added[j])
                pq.push(ver(v.to, j, graph[v.to][j]));
        }
    }
    
    cout<<"Dist: ";
    copy(dist.begin(), dist.end(), ostream_iterator<int> (cout, " ")); cout<<"\n";
}

int main()
{
  
    /* Let us create the example graph discussed above */
    vector<vector<int>> graph = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                                { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                                { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                                { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                                { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                                { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                                { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                                { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                                { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);

    return 0;
}