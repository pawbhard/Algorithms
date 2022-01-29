//https://leetcode.com/problems/word-break/
#include<bits/stdc++.h>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    if(s.length() == 0) return true;
    unordered_set<string> st;
    for (auto w: wordDict) {
        st.insert(w);
    }

    for (int i = 1; i <= s.length(); i++) {
        if(st.find(s.substr(0,i)) != st.end())
        {
            if (wordBreak(s.substr(i),wordDict)) {
                return true;
            }
        }
    }
    return false;
}

bool wordBreak_dp(string s, vector<string>& wordDict) {
    if(s.length() == 0) return true;
    int sz = s.length();
    unordered_set<string> st;
    for (auto w: wordDict) {
        st.insert(w);
    }

    vector<bool> mem(sz+1, 0);
    mem[0] = 1;
    for (int i = 1; i <= s.length(); i++) {
        for (int j = i-1; j>= 0; j--) {
            if(mem[j]) {
                if(st.find(s.substr(j,i-j)) != st.end()) {
                    mem[i] = true;
                }
            }
        }
    }
    return mem[s.length()];
}

int main() {
    
    //string s = "catsanddog";
    //vector<string> wordDict {"cats","dog","sand","and","cat"};
    string s = "leetcode";
    vector<string> wordDict{"leet","code"};
    cout<<wordBreak(s,wordDict)<<" "<<wordBreak_dp(s, wordDict)<<endl;
    return 0;
}
