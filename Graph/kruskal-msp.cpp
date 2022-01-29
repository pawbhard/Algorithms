//Kruscal msp
#include<bits/stdc++.h>

using namespace std;

class QuickUnion {
    vector<int> arr;
    vector<int> sz; //to track component size
    int root(int i) {
        while(i != arr[i]) {
            //try to shorten the path
            //arr[i] = arr[arr[i]];
            i = arr[i];
        }
        return i;
    }
public:
    QuickUnion(int n) {
        arr.resize(n, 0);
        for(int i = 0; i < n; i++) arr[i] = i;
        sz.resize(n, 1);
    }

    void unite(int i, int j) {
        int ri = root(i);
        int rj = root(j);
       
        if (sz[ri] < sz[rj]) {
            arr[ri] = rj;
            sz[rj] += sz[ri];
        } else {
            arr[rj] = ri;
            sz[ri] += sz[rj];
        }
    }

    bool isSame(int i, int j) {
        return root(i) == root(j);
    }

};


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

int kruscal(vector<edge> &edges, int &n) {

    /* We could have just sorted the edges and used that no need of priority queue here*/

    priority_queue<edge, vector<edge>, compare> pq;
    for(auto e: edges) {
        pq.push(e);
    }

    int cost = 0;
    QuickUnion qu(n);    
    //add condition
    int num_edges = 0;
    while (num_edges != n-1) {
        if (pq.empty()) {
            cout<<"Not possible to connect all \n"; 
            return -1;
        }
        edge e = pq.top();
        pq.pop();
        if(not qu.isSame(e.from, e.to)) {
            cout<<"Using edge "<<e.from<<"-"<<e.to<<" wt:"<<e.weight<<"\n";
            qu.unite(e.from, e.to);
            cost += e.weight;
            num_edges++;
        }
    }
    return cost;
}

int main() {
    freopen("input.txt","r",stdin);
    int n; //num of vertices
    int m; //num of edges
    cin>>n;
    cin >>m;
    vector<edge> edges{};
    int from, to, wt;
    for(int i = 0; i < m; i++) {
        cin >> wt>> from>> to;
        //cout<<"New edge "<<from<<"-"<<to<<" wt:"<<wt<<"\n";
        edges.push_back(edge(from,to, wt));
    }
    int cost = kruscal(edges, n);
    cout<<"Cost MST "<<cost<<"\n";
    return 0;
}