//https://leetcode.com/problems/longest-valid-parentheses/
#include <bits/stdc++.h>

using namespace std;


int longestValidParentheses(string s) {
    
    int len = 0;
    stack<int> st;
    st.push(-1);

    for(int i = 0; i < s.length(); i++) {
        int t = st.top();
        if (t != -1 and s[i]== ')' and s[t] == '(') {
            st.pop();
            len = max(len, i-st.top());
        } else {
            st.push(i);
        }
    }
    return len;
}

int main() {
    string s;
    while(cin>>s) {
    cout<<" "<<longestValidParentheses(s)<<endl;
    }
    return 0;
}
