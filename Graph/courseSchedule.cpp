#include<bits/stdc++.h>
using namespace std;



bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses, vector<int>{});
    vector<int> degree(numCourses,0); //incoming edges

    //for adjacency list
    for(auto v: prerequisites) {
        adj[v[0]].push_back(v[1]);
        degree[v[1]]++;
    }

    //There should be one vertex where there is no incoming edges
    queue<int> q;
    vector<int> topo_order; //if possible print it
    for(int i = 0; i <numCourses; i++) {
        if(degree[i]== 0) q.push(i);
    }
    int count = 0;
    while(not q.empty()) {
        int curr = q.front();
        q.pop();
        topo_order.push_back(curr);
        count +=1;
        //reduce in degree of neighbor and add if it become 0
        for (int ne: adj[curr]) {
            degree[ne]--;
            if (degree[ne] == 0)
                q.push(ne);
        }
    }
    copy(topo_order.begin(), topo_order.end(), ostream_iterator<int>(cout," "));
    cout<<endl;
    return count == numCourses;
}

int main() {
    vector<vector<int>> pre {{0,1},{0,2},{1,2},{1,3}, {2,3},{3,4},{4,0}};
    int num = 5;
    canFinish(num, pre);
    //cout<<canFinish(num, pre)<<endl;
    return 0;
}