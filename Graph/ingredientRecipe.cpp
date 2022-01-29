//https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/
#include <bits/stdc++.h>
using namespace std;

vector<string> findAllRecipes(vector<string>& recipes, 
                              vector<vector<string>>& ingredients,
                              vector<string>& supplies) {
    unordered_set<string> supp;
    //Store indegree (number of things needed to make receipie)
    unordered_map<string,int> indegree;

    for (string s: supplies) {
        supp.insert(s);
    }

    //create adjencylist and add indegrees
    unordered_map<string, vector<string>> adj;

    for (int i = 0; i < ingredients.size(); i++) {
        for(int j = 0; j < ingredients[i].size(); j++) {
            adj[ingredients[i][j]].push_back(recipes[i]);
            indegree[recipes[i]]++;
        }
    }

    queue<string> q;
    for (auto s: supplies) {
        indegree[s] =0;
        q.push(s);
    }

    //Algorithm to get topological order
    while (not q.empty()) {
        string s = q.front();
        q.pop();
        for (auto neigh: adj[s]) {
            indegree[neigh]--;
            if (indegree[neigh]== 0) q.push(neigh);
        }
    }

    vector<string> res;
    for(auto s: recipes) {
        if (indegree[s]==0) res.push_back(s);
    }
    return res;
} 

int main() {
    vector<string> recipes {"xevvq","izcad","p","we","bxgnm","vpio","i","hjvu","igi","anp","tokfq","z","kwdmb","g","qb","q","b","hthy"}; 
    vector<vector<string>> ingredients {{"wbjr"},{"otr","fzr","g"},{"fzr","wi","otr","xgp","wbjr","igi","b"},{"fzr","xgp","wi","otr","tokfq","izcad","igi","xevvq","i","anp"},{"wi","xgp","wbjr"},{"wbjr","bxgnm","i","b","hjvu","izcad","igi","z","g"},{"xgp","otr","wbjr"},{"wbjr","otr"},{"wbjr","otr","fzr","wi","xgp","hjvu","tokfq","z","kwdmb"},{"xgp","wi","wbjr","bxgnm","izcad","p","xevvq"},{"bxgnm"},{"wi","fzr","otr","wbjr"},{"wbjr","wi","fzr","xgp","otr","g","b","p"},{"otr","fzr","xgp","wbjr"},{"xgp","wbjr","q","vpio","tokfq","we"},{"wbjr","wi","xgp","we"},{"wbjr"},{"wi"}};
    vector<string> supplies {"wi","otr","wbjr","fzr","xgp"};
    vector<string> res = findAllRecipes(recipes, ingredients, supplies);
    copy(res.begin(), res.end(), ostream_iterator<string> (cout," "));
    cout<<endl;
    return 0;
}