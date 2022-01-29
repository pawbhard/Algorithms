//
//Maximize Palindrome Length From Subsequences

//https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/
#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(string word1, string word2) {
    int res = 0;
    int w1_l = word1.length();
    string s = word1+word2;
    int sz = s.length();

    vector<vector<int>> mem(sz, vector<int>(sz,0));
    for (int i = 0; i < sz; i++) {
        mem[i][i] = 1;
    }
    
    for (int start = sz -2; start >= 0; start--) {
        for (int end = start+1; end < sz; end++) {
            if (s[start] ==s[end]) {
                mem[start][end] = mem[start+1][end-1]+2 ;
                if (start< w1_l and end > w1_l) {
                    if (mem[start][end] > res) {
                        //cout<<"Start: "<<start<<" end: "<<end;
                        res = mem[start][end];
                    }
                }
            } else {
                mem[start][end] = max(mem[start+1][end], mem[start][end-1]);
            }
            //As one should be in first and one should be in second update accordingly
        
        }
    }
    for(auto v: mem) {
        for(int i: v) {
            cout<<i<<"\t";
        }
        cout<<endl;
    }
    return res;
}

int main() {
    cout<<longestPalindrome("baacaab","dcddc")<<endl;
    return 0;
}