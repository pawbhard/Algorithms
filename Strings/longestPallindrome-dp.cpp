#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
//count pallindrome

bool isPallindrome(string &s, int start, int end) {
    for(int i = start, j = end; i <= j; i++, j--) {
        if (s[i] != s[j]) return false; 
    }
    //cout<<s.substr(start, end -start+1)<<" ";
    return true;
}

int recursive(string& s) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            count += isPallindrome(s,i,j);
        }
    }
    return count;
}

bool isPallindrome_mem(string &s, int start, int end, vector<vector<int>> &mem) {
    if(start >= end) return 1;
    if (mem[start][end] != -1) return mem[start][end];
    if (s[start] != s[end]) return mem[start][end] = 0;
    if (isPallindrome_mem(s, start+1, end-1, mem)) return mem[start][end] = 1;
    //cout<<s.substr(start, end -start+1)<<" ";
    return mem[start][end] = 0;
}

int memoization(string& s) {
    int count = 0;
    int slen = s.length();
    if (slen < 1) return 0;
    vector<vector<int>> mem(slen,vector<int>(slen, -1));

    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            count += isPallindrome_mem(s,i,j,mem);
        }
    }
    return count;
}

int tabulation(string& s) {
    int count = 0;
    int slen = s.length();
    if (slen < 1) return 0;
    vector<vector<int>> mem(slen,vector<int>(slen, -1));

    for (int i = s.length()-1; i >= 0; i--) {
        for (int j = i; j < s.length(); j++) {
            if(i == j) mem[i][j] = 1;
            else if (i+1== j) mem[i][j] = (s[i] == s[j]);
            else if (s[i] != s[j]) mem[i][j] = 0;
            else mem[i][j] = mem[i+1][j-1];

            if(mem[i][j]) count++;
        }
    }
    return count;
}

int main() {
    string s = "acaaabbmaalaanitinwasalolassasdfghjklkjhgfderfderf";
    auto point1 = high_resolution_clock::now();
    cout<<recursive(s)<<endl;
    auto point2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds> (point2-point1);
    cout<<"Time took by recursive is : "<<duration.count()<<endl;
    point1 = high_resolution_clock::now();
    cout<<memoization(s)<<endl;
    point2 = high_resolution_clock::now();
    duration = duration_cast<microseconds> (point2-point1);
    cout<<"Time took by rmemoization is : "<<duration.count()<<endl;
    point1 = high_resolution_clock::now();
    cout<<tabulation(s)<<endl;
    point2 = high_resolution_clock::now();
    duration = duration_cast<microseconds> (point2-point1);
    cout<<"Time took by tabulation is : "<<duration.count()<<endl;
    return 0;
}