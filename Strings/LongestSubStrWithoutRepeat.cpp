#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> hash_map{};
    int maxl = 0;
    int max_now = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        auto it = hash_map.find(c);
        if(it != hash_map.end()) {
            if (max_now >= i - it->second)
                max_now = i - it->second;
            else
                max_now++;
        } else {
            max_now++;
        }
        hash_map[c] = i;
        if(max_now >  maxl) maxl = max_now;
    }
    return maxl;
}

int main() {
    string s;
    do {
        cin>>s;
        cout<<s<<" - "<<lengthOfLongestSubstring(s)<<endl;
    } while (s != "q");
    return 0;
}