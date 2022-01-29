//https://leetcode.com/problems/decode-ways/
#include <bits/stdc++.h>
using namespace std;


int numDecodings(string& s, int i) {
    if (i >= s.length()) return 1;
    //base cases
    if (s[i] == '0') return 0;
    if (i == s.length()-1) return 1;

    int val = stoi(s.substr(i,2));
    if (val <= 26) {
        //Two possibilities
        return numDecodings(s,i+1) + numDecodings(s, i+2);
    } else {
        //only one possible
        return numDecodings(s,i+1);
    }
    return 0; 
}

int dp(string &s) {
    //base cases
    if (s.length() == 0) return 0;
    if (s[0] == '0') return 0;
    
    vector<int> mem(s.length()+1, 0);
    mem[0] = 1;
    mem[1] = 1;
    for(int i = 2; i < s.length(); i++) {
        char c1 = s[i-1];
        char c2 = s[i-2];

        if (c1 > '0')
            mem[i] += mem[i-1];
        
        if (c2 == '1' or c2 == '2') {
            int num = (c2 - '0') * 10 + (c1 - '0');
            if (num <= 26) mem[i] += mem[i-2];
        }
    }
    copy(mem.begin(), mem.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    return mem[s.length()];
}
int main() {
    string s;
    do {
        cin >> s;
        cout<<numDecodings(s,0)<<endl;
        int dp_val = dp(s);
        cout<<"Using dp "<<dp_val<<endl;
    } while(s != "0");
    return 0;
}