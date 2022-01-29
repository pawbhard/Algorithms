#include <bits/stdc++.h>
using namespace std;


string multiplyStrings(string s1, string s2) {
    if (s1.length() == 0 or s2.length() == 0) {
        return "0";
    }
    bool isNeg = false;
    if ((s1[0] == '-' and  s2[0] != '-') or (s1[0] != '-' and s2[0] == '-'))
        isNeg = true;
    if (s1[0] == '-') s1 = s1.substr(1);
    if (s2[0] == '-') s2 = s2.substr(1);

    size_t s1_len = s1.length();
    size_t s2_len = s2.length();

    vector<int> res(s1_len + s2_len, 0);
    for (int i = 0; i < s2_len; i++) {
        int s2_num = s2[s2_len - i -1] - '0';
        int carry = 0;
        int j;
        for (j = 0; j < s1_len; j++) {
            int s1_num = s1[s1_len - j -1] - '0';
            int sum = s2_num * s1_num + carry;
            int s = sum % 10;
            carry = sum / 10;
            res[i+j] += s;
        }
        res[i+j] += carry;
    }


    //Adjust carry 
    int carry = 0;
    for (int i = 0; i < res.size(); i++) {
        int tmp = res[i] + carry;
        carry = tmp / 10;
        res[i] = tmp % 10;
    }
    
    reverse(res.begin(), res.end());
    string s = "";
    for (int ele : res) {
        if (s == "" and ele == 0) continue;
        s += to_string(ele);
    }
    if (s == "") s = "0";
    else if (isNeg) s= "-" + s;

    //copy(res.begin(), res.end(), ostream_iterator<int> (cout, " "));
    //cout<<endl;
    return s;
}

int main() {
    string str1 = "1235421415454545454545454544";
    string str2 = "1714546546546545454544548544544545";
    cout<<multiplyStrings(str1, str2)<<endl;
    return 0;
}