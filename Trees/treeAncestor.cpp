#include <bits/stdc++.h>

using namespace std;


class TreeAncestor {
    vector<vector<int>> anc;
    int m;
public:
    TreeAncestor(int n, vector<int>& parent) {
        m = log2(n) + 1;
        cout<<m<<"\n";
        anc.resize(m, vector<int>(n,0));
        anc[0] = parent;
        for (int j = 1; j < m; j++) {
            for(int i = 0; i < n; i++) {
                anc[j][i] = anc[j-1][i] == -1 ? -1 : anc[j-1][anc[j-1][i]];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if (k >= (1<<m)) return -1;
        while(k > 0) {
            int l = log2(k);
            k = k - (1<<l);
            cout<<"Getting l="<<l<<" node= "<<node<<"\n";
            node = anc[l][node];
            if (node == -1) break;
        }
        return node;
    }
    void dump() {
        cout<<"Dump \n";
        for(int i = 0; i < 26; i++) cout<<i<<"\t";
        cout<<"\n";
        for (auto v : anc) {
            copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));
            cout<<"\n";
        }
    }
};

int main() {
    //vector<int> parent {-1, 0, 0, 1, 1,2,2,3,3,4,4,5,5,6,6,7,8,8,12,12,18,19,19,22,22,24};
    vector<int> parent(33,0);
    for(int i = 0; i <33; i++) parent[i] = i -1;
    TreeAncestor* obj = new TreeAncestor(33, parent);
    obj->dump();
    cout<<obj->getKthAncestor(32,33)<<" ";
    return 0;
}

