#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int n, m;
    cin>>n>>m;

    //unordered_map<int, node> graph;
    vector<vector<int>> graph(n, vector<int>{});
    vector<int> in_degree(n,0);
    priority_queue<int,vector<int>,greater<int>> min_pq;
    int from,to;
    for(int i = 0; i < m; i++) {
        cin>>from>>to;
        from--; to--;
        graph[from].push_back(to);
        in_degree[to]++;
    }

    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) min_pq.push(i);
    }

    vector<int> res;
    while(not min_pq.empty()) {
        int curr = min_pq.top();
        min_pq.pop();
        res.push_back(curr);
        //reduce all neigh in_degree
        for(int n: graph[curr])
            if (--in_degree[n] == 0)
                min_pq.push(n);
    }

    if (res.size() != n) {
        cout<<"Sandro fails.\n";
        return 0;
    }

    for(auto i = res.begin(); i!= res.end(); i++) {
        cout<<(*i)+1<<" ";
    }
    cout<<"\n";
    return 0;
}