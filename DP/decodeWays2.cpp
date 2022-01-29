//https://leetcode.com/problems/decode-ways/
#include <bits/stdc++.h>
using namespace std;

int dp(string &s) {
    //base cases
    if (s.length() == 0) return 0;
    if (s[0] == '0') return 0;
    
    vector<long long> mem(s.length()+1, 0);
    mem[0] = 1;
    if (s[0] == '*') mem[1] = 9;
    else mem[1] = 1;
    for(int i = 2; i <= s.length(); i++) {
        char c1 = s[i-1];
        char c2 = s[i-2];

        if (c1 == '*') {
            mem[i] += 9 * mem[i-1];
        } else if (c1 > '0') {
            mem[i] += mem[i-1];
        }

        if (c2 == '*') {
            if (c1 == '*') {
                mem[i] += 15 * mem[i-2];
            } else if  (c1 <= '6') {
                mem[i] += 2 * mem[i-2];
            } else {
                mem[i] += mem[i-2];
            }
        } else if (c2 == '1' or c2 == '2') {
            if (c1 == '*') {
                if (c2 == '1') mem[i] += 9* mem[i-2];
                else mem[i] += 6* mem[i-2];
            } else {
                int num = (c2 -'0')*10+ (c1-'0');
                if (num <= 26) mem[i] += mem[i-2];
            }
        }

        mem[i] = mem[i] % 1000000007;
    }
    copy(mem.begin(), mem.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    return mem[s.length()];
}
int main() {
    string s;
    do {
        cin >> s;
        int dp_val = dp(s);
        cout<<"Using dp "<<dp_val<<endl;
    } while(s != "0");
    return 0;
}