/* https://leetcode.com/problems/longest-palindromic-subsequence/
   https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/
*/

#include <bits/stdc++.h>


using namespace std;

int longestPalindromeSubseq(string s) {
    int sz = s.length();
    vector<vector<int>> mem (sz, vector<int>(sz,0));

    for(int i = 0; i < sz; i++) {
        mem[i][i] = 1;
    }
    
    /* Example for abcdcab
        checking for b, ab, cab, .....
    */

    for (int start = sz - 2; start >= 0; start--) {
        for (int end = start+1;end < sz; end++) {
            if (s[start] == s[end]) mem[start][end] = mem[start+1][end-1] + 2;
            else mem[start][end] = max(mem[start][end-1], mem[start+1][end]);
        }
    }
    return mem[0][sz-1];
}

int maxProduct(string s) {
    //Trick is to generate all combination of string partion and 
    // calculate longestPallindrome individaully and find the max product
    int max_p = 0;
    int sz = s.length();

    for (int i = 0; i < (1<<sz)-1; i++) {
        string s1{},s2{};
        for (int j = 0; j < sz; j++) {

            if (i & 1<<j) {
                s1.push_back(s[i]);
            } else {
                s2.push_back(s[i]);
            }
        }
        max_p = max(max_p, longestPalindromeSubseq(s1) * longestPalindromeSubseq(s2));
    }
    return max_p;
}



int main() {
    cout<<longestPalindromeSubseq("aa")<<endl;
    return 0;
}