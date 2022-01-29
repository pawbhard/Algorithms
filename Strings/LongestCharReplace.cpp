#include<bits/stdc++.h>

using namespace std;

bool compare(pair<char, int> a, pair<char,int> b) {
    return a.second < b.second;
}

int characterReplacement(string s, int k) {
    int res = 0;
    int start =0, end = 1;
    unordered_map<char,int> hash_map{};
    //init the hash_map
    for (int i = 0; i < 26; i++) {
        hash_map[i + 'A'] = 0;
    }
    
    hash_map[s[0]] = 1;

    for(;end < s.length(); end++) {
        char c = s[end];
        hash_map[c]++;

        auto it = max_element(hash_map.begin(), hash_map.end(), compare);
        int len = end - start + 1;
        if(len - it->second > k) {
            //shift sliding window
            hash_map[s[start]]--;
            start++;
        } else if (len > res) {
            res = len;
        }
    }
    return res;
}

//Optimise for speed
int characterReplacement1(string s, int k) {
    int res = 0;
    int start =0, end = 1;
    vector<int> count(26,0);
    //init the hash_map

    int max_freq = 1;
    count[s[0] - 'A'] = 1;

    for(;end < s.length(); end++) {
        int c = s[end] - 'A';
        count[c]++;
        max_freq = max(count[c], max_freq);
        int len = end - start + 1;
        if(len - max_freq > k) {
            //shift sliding window
            count[s[start]-'A']--;
            start++;
        } else if (len > res) {
            res = len;
        }
    }
    return res;
}


int main() {
    cout<<characterReplacement1("AABABBA", 1)<<endl;
    cout<<characterReplacement1("AABABBA", 2)<<endl;
    cout<<characterReplacement1("ABBBA", 2)<<endl;
    cout<<characterReplacement1("ABBBBBB", 1)<<endl;
    //cout<<characterReplacement("AABABBA", 1)<<endl;
    //cout<<characterReplacement("AABABBA", 1)<<endl;

    return 0;
}
