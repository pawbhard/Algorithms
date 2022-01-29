//https://leetcode.com/problems/longest-common-subsequence/
#include <bits/stdc++.h>

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int s1 = text1.length();
    int s2 = text2.length();
    if (s1 == 0 || s2 == 0) return 0;
    vector<vector<int>> mem(s1+1, vector<int>(s2+1,0));

    for (int i = 1; i <= s1; i++) {
        for (int j = 1; j <= s2; j++) {
            if(text1[i-1] == text2[j-1]) {
                mem[i][j] =  mem[i-1][j-1]+1;
            } else {
                mem[i][j] = max(mem[i-1][j], mem[i][j-1]);
            }
        }
    }
    return mem[s1][s2];
}

//https://leetcode.com/problems/delete-operation-for-two-strings/
int minDistance(string word1, string word2) {
    return word1.length() + word2.length() - 2 * longestCommonSubsequence(word1,word2);        
}
int main() {
    cout<<longestCommonSubsequence("abcdcab", "cabab")<<endl;
    return 0;
}
