#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> hash_map;
    vector<vector<string>> res {};

    for (string s : strs) {
        string ns = s;
        sort(ns.begin(), ns.end());

        auto it = hash_map.find(ns);
        if (it == hash_map.end()) {
            hash_map[ns] = vector<string> {s};
        } else {
            it->second.push_back(s);
        }
    }

    for (auto it : hash_map) {
        res.push_back(it.second);
    }
    return res;
}

int main() {
    vector<string> list {"eatt","taet", "tea","tan","ate","nat","bat"};
    vector<vector<string>> res = groupAnagrams(list);

    //Print
    for (auto v: res) {
        cout<<"[";
        for (string s : v) {
            cout<<s<<",";
        }
        cout<<"]";
    }
    cout<<endl;
    return 0;
}