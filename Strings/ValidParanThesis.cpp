#include<bits/stdc++.h>

using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c: s) {
        if (c == '(' or c == '{' or c == '[') {
            st.push(c);
        } else if (st.empty()) {
            return false;
        } else {
            if ((c == ')' and st.top() == '(') or
                (c == '}' and st.top() == '{') or
                (c == ']' and st.top() == '[')) {
                    st.pop();
            } else {
                return false;
            } 
        }
    }
    return st.empty();
}

int main() {
    cout<<isValid("()")<<endl;
    cout<<isValid("(){")<<endl;
    cout<<isValid("()]")<<endl;
    cout<<isValid("(){}")<<endl;
    cout<<isValid("[{(){}}]")<<endl;


}