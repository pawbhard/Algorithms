#include<bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    vector <int> map(128,0);
    int counter = t.size();

    int start = 0, end = 0;
    int left = -1, len = INT_MAX;

    for(char c: t) { map[c]++; }

    while(end < s.size() and start <= end) {
        if (map[s[end++]]-- > 0) counter--; //in t

        while(counter == 0) {//valid condition
            if (len > end - start) {
                left = start;
                len = end - start;
            }
            //change start to make it valid/invalid
            if (map[s[start++]]++ == 0) counter++; 
        }
    }
    if(left == -1) return "";
    return s.substr(left, len);
}

int main() {

    cout<<"Val : ADOBECODEBANCD ABC = "<<minWindow("ADOBECODEBANC", "ABC")<<endl;
    cout<<"Val : a aa = "<<minWindow("a", "aa")<<endl;
    cout<<"Val : aa a = "<<minWindow("aa", "a")<<endl;
    cout<<"Val : a a  = "<<minWindow("a", "a")<<endl;
    cout<<"Val : ab a = "<<minWindow("ab", "a")<<endl;
    cout<<"Val : abc b = "<<minWindow("abc", "b")<<endl;
    //cout<<"Val : cabwefgewcwaefgcf cae = "<<minWindow("cabwefgewcwaefgcf","cae")<<endl;
    return 0;
}